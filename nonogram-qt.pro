QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += static

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cluenumberbutton.cpp \
    flowlayout.cpp \
    linesolver.cpp \
    main.cpp \
    mainmenu.cpp \
    nonogram.cpp \
    nonogramexport.cpp \
    pushbutton.cpp \
    puzzlecreator.cpp \
    puzzlegame.cpp \
    puzzlegenerator.cpp \
    puzzlelibrary.cpp \
    solver.cpp \
    tile.cpp

HEADERS += \
    cluenumberbutton.h \
    flowlayout.h \
    linesolver.h \
    mainmenu.h \
    nonogram.h \
    nonogramexport.h \
    pushbutton.h \
    puzzlecreator.h \
    puzzlegame.h \
    puzzlegenerator.h \
    puzzlelibrary.h \
    solver.h \
    tile.h

FORMS += \
    mainmenu.ui \
    puzzlecreator.ui \
    puzzlegame.ui \
    puzzlegenerator.ui \
    puzzlelibrary.ui \
    tile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    translations/nonogram_cs.qm \
    translations/nonogram_cs.ts \
    translations/nonogram_fi.qm \
    translations/nonogram_fi.ts \
    translations/nonogram_sv.qm \
    translations/nonogram_sv.ts

RC_ICONS = icon.ico
