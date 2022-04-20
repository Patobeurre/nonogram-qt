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


/**
 * @brief Implementation of the puzzle library
 *
 * Display all custom puzzles as tiles which contains
 * the puzzle's name and size.
 *
 * Provides two sorting options:
 *  - alphabetical
 *  - size
 *
 * @author Patobeur
 */
class PuzzleLibrary : public QWidget
{
    Q_OBJECT

private:
    /// The list of all puzzle tiles
    vector<Tile*> *puzzles;
    /// The main layout
    FlowLayout *flow;
    Ui::PuzzleLibrary *ui;

    /// Gather all puzzle informations
    void load();
    /// Display tiles
    void displayTiles();

public:
    /// Constructor
    explicit PuzzleLibrary(QWidget *parent = 0);
    ~PuzzleLibrary();

public slots:
    /// Load a puzzle
    void loadPuzzle(QString path);

private slots:
    /// Button actions for sort options
    void on_btn_sortAlpha_clicked();
    void on_btn_sortSize_clicked();
};

#endif // PUZZLELIBRARY_H
