#ifndef PUZZLEGAME_H
#define PUZZLEGAME_H

#include "cluenumberbutton.h"
#include "pushbutton.h"
#include "nonogram.h"

#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpinBox>
#include <QMessageBox>
#include <QCommonStyle>
#include <QSignalMapper>
#include <QString>
#include <vector>
#include <QDebug>

#define UNKNOWN 2
#define DOT 1
#define SOLID 0

namespace Ui {
class PuzzleGame;
}

class PuzzleGame : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *grid;
    QCommonStyle *style;
    QSignalMapper *mapperLeftButton;
    QSignalMapper *mapperRightButton;
    vector<PushButton*> puzzle;
    vector<vector<ClueNumberButton*>> xAxis, yAxis;
    vector<uint64_t> **xAxisClue;
    vector<uint64_t> **yAxisClue;
    vector<int> status;
    uint64_t width, height;
    int mouseButton;
    bool firstClick, lockAction;
    Nonogram *ngram;

    Ui::PuzzleGame *ui;

    void generatePuzzle();
    void fillBlanks();
    void fillLineBlanks(int index);
    void fillColumnBlanks(int index);

public:
    explicit PuzzleGame(Nonogram *n, QWidget *parent = 0);
    ~PuzzleGame();

public slots:
    void clear();

private slots:
    void cleanUp();
    void giveUp();
    void solidClicked(int position);
    void dotClicked(int position);
    void checkSolution();

};

#endif // PUZZLEGAME_H
