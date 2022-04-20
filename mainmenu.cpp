#include "mainmenu.h"
#include "ui_mainmenu.h"


MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::about() {
    QMessageBox mb;
    mb.setWindowTitle(tr("About"));
    mb.setText(tr("<p><h3>Nonogram-qt 1.1.1</h3></p><p>Copyright: Daniel Suni, 2012, 2013, 2018</p><p>Distributed under the GNU GPL v3</p>"));
    mb.exec();
}

void MainMenu::help() {
    QWidget *helpWindow = new QWidget();
    helpWindow->setWindowTitle(tr("Help"));
    QHBoxLayout *bl = new QHBoxLayout(helpWindow);
    QLabel *text = new QLabel(tr("<h2>What are nonograms?</h2>\
<p>Nonograms are logic puzzles consisting of a rectangular grid divided into cells. These cells can be either<br>\
colored (solids) or blank (dots). At the start of the game all cells are blank, and the purpose of the game is<br>\
to figure out which ones should be colored.</p>\
<p>Each row and column in the grid is fitted with a clue consisting of a series of numbers. These numbers reveal<br>\
how many solids there are on the row/column as well as something about their grouping. If e.g. the clue is<br>\
(3 1 2) we know that from left to right there is first a series of 3 consequtive solids, then X number of blanks,<br>\
where X >= 1, then a single solid, then another unspecified number of blanks, and finally 2 consequtive solids.<br>\
If the row was 10 cells long, one possible arrangement would be (-###-#--##), another one would be (###-#-##--).<br>\
Since there are rules for both rows and columns, only one arrangement is actually correct, though. The puzzle is<br>\
to find the arrangement that conforms to all the given clues.</p>\
<h2>How to play</h2>\
<p>In order to start a new game, please select the size of the desired playing field, and click the &quot;Generate puzzle&quot;<br>\
button. Generating the puzzle can take a few seconds - especially if it's a big one, so please be patient.</p>\
<p>When starting all cells are blank. You can mark a cell as a solid by clicking on it. You can also mark larger areas<br>\
by dragging the mouse with the button pressed. If you've made a mistake, just click the cell again to revert it to a<br>\
dot. You can also mark known dots by right clicking (and dragging). This will be shown by an 'X' appearing in that<br>\
cell. Notice that you don't need to explicitly mark the dots in order to solve the puzzle. That functionality only<br>\
exists for your own convenience.</p>\
<p>Every time you make a move the computer will automatically check whether you've successfully solved the puzzle<br>\
 or not. Once the puzzle is solved, you will immediately be informed. If the puzzle turns out to be too hard, you can<br>\
end it, and look at the solution by pressing the &quot;Give up&quot; button. Remaining solids will be displayed in<br>\
grey, and possible mistakes (i.e. dots marked as solids) will be displayed in red.</p>"), helpWindow);
    helpWindow->setLayout(bl);
    bl->addWidget(text);
    helpWindow->show();
}

void MainMenu::quit() {
    delete ui;
    exit(0);
}

void MainMenu::clearLayout() {
    QLayoutItem *child;
    while ((child = ui->layout->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }
}

/**
 * Create the
 */
void MainMenu::on_btn_random_clicked()
{
    clearLayout();
    ui->layout->addWidget(new PuzzleGenerator());
}

void MainMenu::on_btn_library_clicked()
{
    clearLayout();
    ui->layout->addWidget(new PuzzleLibrary());
}

void MainMenu::on_btn_build_clicked()
{
    clearLayout();
    ui->layout->addWidget(new PuzzleCreator());
}
