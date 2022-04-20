#ifndef PUZZLELIBRARY_H
#define PUZZLELIBRARY_H

#include "nonogram.h"
#include "nonogramexport.h"
#include "puzzlegame.h"
#include "flowlayout.h"
#include "tile.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

namespace Ui {
class PuzzleLibrary;
}

class PuzzleLibrary : public QWidget
{
    Q_OBJECT

private:
    vector<Tile*> *puzzles;
    FlowLayout *flow;
    Ui::PuzzleLibrary *ui;

    void load();
    void displayTiles();

public:
    explicit PuzzleLibrary(QWidget *parent = 0);
    ~PuzzleLibrary();

public slots:
    void loadPuzzle(QString path);

private slots:
    void on_btn_sortAlpha_clicked();
    void on_btn_sortSize_clicked();
};

#endif // PUZZLELIBRARY_H
