#include "puzzlelibrary.h"
#include "ui_puzzlelibrary.h"


PuzzleLibrary::PuzzleLibrary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PuzzleLibrary)
{
    ui->setupUi(this);

    ui->top->setVisible(true);

    puzzles = new vector<Tile*>();
    flow = new FlowLayout();

    load();
    displayTiles();
}

void PuzzleLibrary::load() {
    QDir dir;
    dir.cd(QDir::currentPath());
    if (!dir.exists(FOLDER)) {
        dir.mkdir(FOLDER);
    }
    dir.cd(FOLDER);
    QString path = dir.path();

    QStringList fileList = dir.entryList(QDir::Files);

    for (QString filename : fileList) {
        QString fullPath = path + "/" + filename;
        QFile file(fullPath);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            QString line = stream.readLine();
            QStringList data = line.split(',');

            QString name = data.at(0);
            QString width = data.at(1);
            QString height = data.at(2);

            Tile *tile = new Tile(fullPath, name, width, height);
            puzzles->push_back(tile);

            file.close();
        }
    }
}

void PuzzleLibrary::displayTiles() {
    FlowLayout *f = new FlowLayout();

    for (size_t i = 0; i < puzzles->size(); ++i) {
        f->addWidget(puzzles->at(i));
        connect(puzzles->at(i), SIGNAL(click(QString)), this, SLOT(loadPuzzle(QString)));
    }

    delete ui->widget->layout();
    ui->widget->setLayout(f);
}

void PuzzleLibrary::loadPuzzle(QString path) {
    Nonogram *ngram = NonogramExport::importCSV(path);

    delete flow;

    ui->top->setVisible(false);

    QGridLayout *grid = new QGridLayout();
    grid->addWidget(new PuzzleGame(ngram), 0, 0, 0, 0);
    delete ui->widget->layout();
    ui->widget->setLayout(grid);
}

PuzzleLibrary::~PuzzleLibrary()
{
    delete puzzles;
    delete ui;
}

void PuzzleLibrary::on_btn_sortAlpha_clicked()
{
    sort(puzzles->begin(), puzzles->end(), Tile::compareName);
    displayTiles();
}

void PuzzleLibrary::on_btn_sortSize_clicked()
{
    sort(puzzles->begin(), puzzles->end(), Tile::compareSize);
    displayTiles();
}
