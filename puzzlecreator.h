#ifndef PUZZLECREATOR_H
#define PUZZLECREATOR_H

#include "pushbutton.h"
#include "nonogram.h"
#include "nonogramexport.h"

#include <QWidget>
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
class PuzzleCreator;
}

class PuzzleCreator : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *grid;
    QCommonStyle *style;
    QSignalMapper *mapperLeftButton;
    vector<PushButton*> puzzle;
    vector<int> status;
    uint64_t width, height;
    int mouseButton;
    bool firstClick, lockAction;
    QString name;
    Nonogram *ngram;
    Ui::PuzzleCreator *ui;

    void cleanUp();
    bool checkName();
    bool checkEmptyGrid();

public:
    explicit PuzzleCreator(QWidget *parent = 0);
    ~PuzzleCreator();

private slots:
    void generateGrid();
    void solidClicked(int position);
    bool checkSolution();
    void on_btn_finalize_clicked();
};

#endif // PUZZLECREATOR_H
