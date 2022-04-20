#include "puzzlecreator.h"
#include "ui_puzzlecreator.h"

PuzzleCreator::PuzzleCreator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PuzzleCreator)
{
    ui->setupUi(this);

    ui->grid->setSpacing(0);
    ui->grid->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    style = new QCommonStyle();
    lockAction = false;

    connect(ui->btn_generate, SIGNAL(clicked()), this, SLOT(generateGrid()));
}

PuzzleCreator::~PuzzleCreator()
{
    cleanUp();
    delete ui;
}

void PuzzleCreator::generateGrid() {
    cleanUp();

    uint64_t pos, spacer_x, spacer_y;

    width = (uint64_t) ui->widthBox->value();
    height = (uint64_t) ui->heightBox->value();

    // We need to map the clicks and right clicks to the respective methods.
    // Using mappers allows us to easily identify the button that sent the signal.
    mapperLeftButton = new QSignalMapper(this);

    // Create the playing field itself.
    spacer_y = 0;
    for (uint64_t i = 0; i < height; ++i) {
        if (i > 0 && i % 5 == 0) {
            ++spacer_y;
            ui->grid->setRowMinimumHeight(i + spacer_y, 2);
        }
        spacer_x = 0;
        for (uint64_t j = 0; j < width; ++j) {
            if (j > 0 && j % 5 == 0) {
                ++spacer_x;
                ui->grid->setColumnMinimumWidth(j + spacer_x, 2);
            }
            pos = i * width + j;
            status.push_back(UNKNOWN);
            puzzle.push_back(new PushButton(&mouseButton, &firstClick));
            puzzle.at(pos)->setStyle(style);
            connect(puzzle.at(pos), SIGNAL(solid()), mapperLeftButton, SLOT(map()));
            connect(puzzle.at(pos), SIGNAL(released()), this, SLOT(checkSolution()));
            mapperLeftButton->setMapping(puzzle.at(pos), pos);
            ui->grid->addWidget(puzzle.at(pos), i + spacer_y + 1, j + spacer_x + 1);
        }
    }

    connect(mapperLeftButton, SIGNAL(mapped(int)), this, SLOT(solidClicked(int)));
    ui->txt_name->clear();
}

// Cleans up stuff before a new game is started
void PuzzleCreator::cleanUp() {
    if (ui->grid->isEmpty()) return;

    for (uint64_t i = 0; i < width * height; ++i) {
        delete puzzle.at(i);
    }
    name = "";
    puzzle.clear();
    delete mapperLeftButton;
    status.clear();
}

// Called when a button is clicked or dragged over with button depressed.
// The firstClick & lockAction variables are used to determine which call to
// the function represents the first click, then lock the behaviour of the
// function to the behaviour expected from that first click.
void PuzzleCreator::solidClicked(int position) {
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

// Check whether the puzzle is solved or not. Display a message if it is.
bool PuzzleCreator::checkSolution() {
    lockAction = false;

    uint64_t *field = new uint64_t[height];
    uint64_t mask = (uint64_t)1 << (width - 1);
    uint64_t pos = 0;

    for (uint64_t i = 0; i < height; ++i) {
        uint64_t tmp = 0;
        pos = i * width;
        for (uint64_t j = mask; j > 0; j >>=1) {
            if (status.at(pos) == SOLID) {
                tmp |= j;
            }
            pos++;
        }
        field[i] = tmp;
    }

    ngram = new Nonogram(width, height, field);

    vector<uint64_t> **xAxisClue = ngram->getXAxis();
    vector<uint64_t> **yAxisClue = ngram->getYAxis();
    Solver *solv = new Solver(width, height, xAxisClue, yAxisClue);

    if (!solv->solve()) {
        ui->btn_finalize->setEnabled(false);
        delete solv;
        return false;
    }

    ui->btn_finalize->setEnabled(true);
    delete solv;
    return true;
}

bool PuzzleCreator::checkEmptyGrid() {
    uint64_t *field = ngram->getField();

    for (uint64_t i = 0; i < ngram->getHeight(); ++i) {
        if (field[i] > 0) {
            return false;
        }
    }

    return true;
}

bool PuzzleCreator::checkName() {
    name = ui->txt_name->text().trimmed();
    if (name.isEmpty()) {
        return false;
    }
    return true;
}

void PuzzleCreator::on_btn_finalize_clicked() {
    if (!checkSolution()) {
        QMessageBox mb;
        mb.setWindowTitle(tr("Invalid puzzle"));
        mb.setText(tr("Sorry,\nthe puzzle you've made is unsolvable!"));
        mb.exec();
        return;
    }
    if (checkEmptyGrid()) {
        QMessageBox mb;
        mb.setWindowTitle(tr("Invalid puzzle"));
        mb.setText(tr("The puzzle is empty..."));
        mb.exec();
        return;
    }
    if (!checkName()) {
        QMessageBox mb;
        mb.setWindowTitle(tr("Invalid Name"));
        mb.setText(tr("Enter a name for your puzzle"));
        mb.exec();
        return;
    }

    int r = NonogramExport::exportCSV(name, ngram);
    if (r == ERR_FILE_EXISTS) {
        QMessageBox mb;
        mb.setWindowTitle(tr("Export error"));
        mb.setText(tr("A file with the same name already exists"));
        mb.exec();
    }
    else if (r == ERR_WRITE_FILE) {
        QMessageBox mb;
        mb.setWindowTitle(tr("Export error"));
        mb.setText(tr("An error occurred while exporting"));
        mb.exec();
    }
    else {
        QMessageBox mb;
        mb.setWindowTitle(tr("Export info"));
        mb.setText(tr("Export successfuly done!"));
        mb.exec();
    }
}
