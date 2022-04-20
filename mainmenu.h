#ifndef MAINMENU_H
#define MAINMENU_H

#include "puzzlegenerator.h"
#include "puzzlecreator.h"
#include "puzzlelibrary.h"

#include <QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QCommonStyle>
#include <QSignalMapper>
#include <QString>
#include <QDebug>

namespace Ui {
class MainMenu;
}


/**
 * The main window which manages the menu and the main layout.
 */
class MainMenu : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainMenu *ui;

    void clearLayout();

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void quit();
    void help();
    void about();

    void on_btn_random_clicked();
    void on_btn_library_clicked();
    void on_btn_build_clicked();
};

#endif // MAINMENU_H
