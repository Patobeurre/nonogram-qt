#ifndef PUZZLEGENERATOR_H
#define PUZZLEGENERATOR_H

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

#define MIN_PUZZLE_SIZE 3
#define MAX_PUZZLE_SIZE 30
#define DEFAULT_PUZZLE_SIZE 10
#define UNKNOWN 2
#define DOT 1
#define SOLID 0

namespace Ui {
class PuzzleGenerator;
}


class PuzzleGenerator : public QWidget
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

    Ui::PuzzleGenerator *ui;

    void cleanUp();
    void fillBlanks();
    void fillLineBlanks(int index);
    void fillColumnBlanks(int index);

public:
    explicit PuzzleGenerator(QWidget *parent = 0);
    ~PuzzleGenerator();

private slots:
    void generatePuzzle();
    void giveUp();
    void solidClicked(int position);
    void dotClicked(int position);
    void checkSolution();
};

#endif // PUZZLEGENERATOR_H
