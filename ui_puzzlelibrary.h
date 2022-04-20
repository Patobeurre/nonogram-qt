/********************************************************************************
** Form generated from reading UI file 'puzzlelibrary.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUZZLELIBRARY_H
#define UI_PUZZLELIBRARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PuzzleLibrary
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *top;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_sortAlpha;
    QPushButton *btn_sortSize;
    QSpacerItem *spacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;

    void setupUi(QWidget *PuzzleLibrary)
    {
        if (PuzzleLibrary->objectName().isEmpty())
            PuzzleLibrary->setObjectName(QString::fromUtf8("PuzzleLibrary"));
        PuzzleLibrary->resize(400, 300);
        verticalLayout = new QVBoxLayout(PuzzleLibrary);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        top = new QWidget(PuzzleLibrary);
        top->setObjectName(QString::fromUtf8("top"));
        horizontalLayout = new QHBoxLayout(top);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_sortAlpha = new QPushButton(top);
        btn_sortAlpha->setObjectName(QString::fromUtf8("btn_sortAlpha"));
        btn_sortAlpha->setMinimumSize(QSize(40, 40));
        btn_sortAlpha->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(btn_sortAlpha);

        btn_sortSize = new QPushButton(top);
        btn_sortSize->setObjectName(QString::fromUtf8("btn_sortSize"));
        btn_sortSize->setMinimumSize(QSize(40, 40));
        btn_sortSize->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(btn_sortSize);

        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer);


        verticalLayout->addWidget(top);

        scrollArea = new QScrollArea(PuzzleLibrary);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 382, 218));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_2->addWidget(widget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(PuzzleLibrary);

        QMetaObject::connectSlotsByName(PuzzleLibrary);
    } // setupUi

    void retranslateUi(QWidget *PuzzleLibrary)
    {
        PuzzleLibrary->setWindowTitle(QApplication::translate("PuzzleLibrary", "Form", 0));
        btn_sortAlpha->setText(QApplication::translate("PuzzleLibrary", "A-Z", 0));
        btn_sortSize->setText(QApplication::translate("PuzzleLibrary", "Size", 0));
    } // retranslateUi

};

namespace Ui {
    class PuzzleLibrary: public Ui_PuzzleLibrary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUZZLELIBRARY_H
