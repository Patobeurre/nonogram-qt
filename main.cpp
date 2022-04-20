#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include "mainmenu.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QTranslator translator;
    translator.load(":/translations/nonogram_" + QLocale::system().name());
    app.installTranslator(&translator);
    app.setWindowIcon(QIcon(":/icon.png"));
    MainMenu mw;
    mw.show();
    return app.exec();
}
