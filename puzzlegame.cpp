#include "puzzlegame.h"
#include "ui_puzzlegame.h"

PuzzleGame::PuzzleGame(Nonogram *n, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PuzzleGame)
{
    ui->setupUi(this);

    ui->grid->setSpacing(0);
    ui->grid->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    style = new QCommonStyle();
    lockAction = false;
    ngram = n;

    generatePuzzle();

    connect(ui->btn_reset, SIGNAL(clicked()), this, SLOT(clear()));
    connect(ui->btn_surrender, SIGNAL(clicked()), this, SLOT(giveUp()));
}

// Generates, verifies and displays the puzzle and its graphical components.
void PuzzleGame::generatePuzzle() {
    int pos, spacer_x, spacer_y;

    // We need to map the clicks and right clicks to the respective methods.
    // Using mappers allows us to easily identify the button that sent the signal.
    mapperLeftButton = new QSignalMapper(this);
    mapperRightButton = new QSignalMapper(this);
    width = ngram->getWidth();
    height = ngram->getHeight();
    xAxisClue = ngram->getXAxis();
    yAxisClue = ngram->getYAxis();

    // Create and add the clue labels
    spacer_x = 0;
    spacer_y = 0;
    for (uint64_t i = 0; i < width; ++i) {
        QVBoxLayout *vbox = new QVBoxLayout();
        vector<ClueNumberButton*> clues;

        QString num = "";
        for (uint64_t j = 0; j < xAxisClue[i]->size(); ++j) {
            num.setNum(xAxisClue[i]->at(j), 10);

            ClueNumberButton *btn = new ClueNumberButton(&mouseButton);
            btn->ClueNumberButton::setText(num);
            clues.push_back(btn);
            vbox->addWidget(btn);
        }
        xAxis.push_back(clues);
        //xAxis.push_back(new QLabel(str));
        //xAxis.at(i)->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
        // We want to separate the UI buttons in 5 x 5 chunks, so that counting
        // blocks becomes easier for the user.
        if (i > 0 && i % 5 == 0) {
            ++spacer_x;
            ui->grid->setColumnMinimumWidth(i + spacer_x, 2);
        }

        ui->grid->addLayout(vbox, 0, i + spacer_x + 1, 1, 1, Qt::AlignBottom);
    }
    for (uint64_t i = 0; i < height; ++i) {
        QHBoxLayout *hbox = new QHBoxLayout();
        vector<ClueNumberButton*> clues;

        QString num = "";
        for (uint64_t j = 0; j < yAxisClue[i]->size(); ++j) {
            num.setNum(yAxisClue[i]->at(j), 10);

            ClueNumberButton *btn = new ClueNumberButton(&mouseButton);
            btn->ClueNumberButton::setText(num);
            clues.push_back(btn);
            hbox->addWidget(btn);
        }
        yAxis.push_back(clues);
        //yAxis.push_back(new QLabel(str));
        //yAxis.at(i)->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        if (i > 0 && i % 5 == 0) {
            ++spacer_y;
            ui->grid->setRowMinimumHeight(i + spacer_y, 2);
        }
        ui->grid->addLayout(hbox, i + spacer_y + 1, 0, 1, 1, Qt::AlignRight);
    }
    // Create the playing field itself.
    spacer_y = 0;
    for (uint64_t i = 0; i < height; ++i) {
        if (i > 0 && i % 5 == 0) {
            ++spacer_y;
        }
        spacer_x = 0;
        for (uint64_t j = 0; j < width; ++j) {
            if (j > 0 && j % 5 == 0) {
                ++spacer_x;
            }
            pos = i * width + j;
            status.push_back(UNKNOWN);
            puzzle.push_back(new PushButton(&mouseButton, &firstClick));
            puzzle.at(pos)->setStyle(style);
            connect(puzzle.at(pos), SIGNAL(solid()), mapperLeftButton, SLOT(map()));
            connect(puzzle.at(pos), SIGNAL(dot()), mapperRightButton, SLOT(map()));
            connect(puzzle.at(pos), SIGNAL(released()), this, SLOT(checkSolution()));
            mapperLeftButton->setMapping(puzzle.at(pos), pos);
            mapperRightButton->setMapping(puzzle.at(pos), pos);
            ui->grid->addWidget(puzzle.at(pos), i + spacer_y + 1, j + spacer_x + 1);
        }
    }
    connect(mapperLeftButton, SIGNAL(mapped(int)), this, SLOT(solidClicked(int)));
    connect(mapperRightButton, SIGNAL(mapped(int)), this, SLOT(dotClicked(int)));
    // Enable button that lets user see the solution without solving
    fillBlanks();
}

void PuzzleGame::clear() {
    cleanUp();
    generatePuzzle();
}

void PuzzleGame::fillBlanks() {
    for (uint64_t i = 0; i < height; ++i) {
        if (yAxis.at(i).at(0)->isZero()) {
            fillLineBlanks(i);
        }
    }
    for (uint64_t i = 0; i < width; ++i) {
        if (xAxis.at(i).at(0)->isZero()) {
            fillColumnBlanks(i);
        }
    }
}

void PuzzleGame::fillLineBlanks(int index) {
    uint64_t pos = index * width;
    for (uint64_t i = 0; i < width; ++i) {
        dotClicked(pos + i);
    }
}

void PuzzleGame::fillColumnBlanks(int index) {
    for (uint64_t i = index; i < puzzle.size(); i += width) {
        dotClicked(i);
    }
}

// Cleans up stuff before a new game is started
void PuzzleGame::cleanUp() {
    for (int i = 0; i < xAxis.size(); ++i) {
        for (ClueNumberButton *c : xAxis.at(i)) {
            delete c;
        }
    }
    xAxis.clear();
    for (int i = 0; i < yAxis.size(); ++i) {
        for (ClueNumberButton *c : yAxis.at(i)) {
            delete c;
        }
    }
    yAxis.clear();
    for (int i = 0; i < width * height; ++i) {
        delete puzzle.at(i);
    }
    puzzle.clear();
    delete mapperLeftButton;
    delete mapperRightButton;
    status.clear();
}

// Display all solids that the user has missed, in grey and all
// dots he has mistakenly identified as solids in red.
void PuzzleGame::giveUp() {
    ui->btn_surrender->setEnabled(false);
    uint64_t pos;
    for (uint64_t i = 0; i < height; ++i) {
        uint64_t mask = (uint64_t)1 << width;
        for (uint64_t j = 0; j < width; ++j) {
            mask >>= 1;
            pos = i * width + j;
            if (status.at(pos) == SOLID) {
                if (!(ngram->getField()[i] & mask)) {
                    puzzle.at(pos)->setStyleSheet("background-color: rgb(255, 0, 0)");
                }
            }
            else if (ngram->getField()[i] & mask) {
                puzzle.at(pos)->setStyleSheet("background-color: rgb(150, 150, 150)");
            }
        }
    }
}

// Called when a button is clicked or dragged over with button depressed.
// The firstClick & lockAction variables are used to determine which call to
// the function represents the first click, then lock the behaviour of the
// function to the behaviour expected from that first click.
void PuzzleGame::solidClicked(int position) {
    puzzle.at(position)->setText("");
    if (status.at(position) == SOLID) {
        if (firstClick || lockAction) {
            status.at(position) = UNKNOWN;
            puzzle.at(position)->setStyleSheet("background-color: rgb(215, 215, 215)");
            lockAction = true;
        }
    }
    else {
        status.at(position) = SOLID;
        puzzle.at(position)->setStyleSheet("background-color: rgb(50, 50, 50)");
    }
    firstClick = false;
}

// Same as above, but for the right mouse button.
void PuzzleGame::dotClicked(int position) {
    if (status.at(position) == DOT) {
        if (firstClick || lockAction) {
            status.at(position) = UNKNOWN;
            puzzle.at(position)->setText("");
            puzzle.at(position)->setStyleSheet("background-color: rgb(215, 215, 215)");
            lockAction = true;
        }
    }
    else {
        status.at(position) = DOT;
        puzzle.at(position)->setText("X");
        puzzle.at(position)->setStyleSheet("background-color: rgb(215, 215, 215)");
    }
    firstClick = false;
}

// Check whether the puzzle is solved or not. Display a message if it is.
void PuzzleGame::checkSolution() {
    // Since this function is called when the mouse button is released,
    // we use it to unset the lockAction variable.
    lockAction = false;
    for (uint64_t i = 0; i < height; ++i) {
        uint64_t test = 0;
        uint64_t mask = (uint64_t)1 << width;
        for (uint64_t j = 0; j < width; ++j) {
            mask >>= 1;
            if (status.at(i * width + j) == SOLID) {
                test |= mask;
            }
        }
        if (test != ngram->getField()[i]) {
            return;
        }
    }
    for (uint64_t i = 0; i < width * height; ++i) {
        puzzle.at(i)->setEnabled(false);
    }
    QMessageBox mb;
    mb.setWindowTitle(tr("Well done"));
    mb.setText(tr("You have solved the puzzle!"));
    mb.exec();
}

PuzzleGame::~PuzzleGame()
{
    if (ngram) {
        cleanUp();
    }
    delete style;
    style = NULL;
    delete ui;
}
