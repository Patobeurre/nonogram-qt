/********************************************************************************
** Form generated from reading UI file 'puzzlegame.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUZZLEGAME_H
#define UI_PUZZLEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PuzzleGame
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *top;
    QPushButton *btn_reset;
    QPushButton *btn_surrender;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *grid;

    void setupUi(QWidget *PuzzleGame)
    {
        if (PuzzleGame->objectName().isEmpty())
            PuzzleGame->setObjectName(QString::fromUtf8("PuzzleGame"));
        PuzzleGame->resize(582, 430);
        verticalLayout = new QVBoxLayout(PuzzleGame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        top = new QHBoxLayout();
        top->setObjectName(QString::fromUtf8("top"));
        btn_reset = new QPushButton(PuzzleGame);
        btn_reset->setObjectName(QString::fromUtf8("btn_reset"));

        top->addWidget(btn_reset);

        btn_surrender = new QPushButton(PuzzleGame);
        btn_surrender->setObjectName(QString::fromUtf8("btn_surrender"));

        top->addWidget(btn_surrender);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        top->addItem(horizontalSpacer);


        verticalLayout->addLayout(top);

        scrollArea = new QScrollArea(PuzzleGame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 564, 375));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        grid = new QGridLayout();
        grid->setObjectName(QString::fromUtf8("grid"));

        verticalLayout_2->addLayout(grid);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(PuzzleGame);

        QMetaObject::connectSlotsByName(PuzzleGame);
    } // setupUi

    void retranslateUi(QWidget *PuzzleGame)
    {
        PuzzleGame->setWindowTitle(QApplication::translate("PuzzleGame", "Form", 0));
        btn_reset->setText(QApplication::translate("PuzzleGame", "Clear", 0));
        btn_surrender->setText(QApplication::translate("PuzzleGame", "Give Up", 0));
    } // retranslateUi

};

namespace Ui {
    class PuzzleGame: public Ui_PuzzleGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUZZLEGAME_H
