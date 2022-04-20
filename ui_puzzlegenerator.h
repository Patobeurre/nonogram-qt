/********************************************************************************
** Form generated from reading UI file 'puzzlegenerator.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUZZLEGENERATOR_H
#define UI_PUZZLEGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PuzzleGenerator
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *heightBox;
    QLabel *label;
    QSpinBox *widthBox;
    QPushButton *btn_generate;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_surrender;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QGridLayout *grid;

    void setupUi(QWidget *PuzzleGenerator)
    {
        if (PuzzleGenerator->objectName().isEmpty())
            PuzzleGenerator->setObjectName(QString::fromUtf8("PuzzleGenerator"));
        PuzzleGenerator->resize(491, 270);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PuzzleGenerator->sizePolicy().hasHeightForWidth());
        PuzzleGenerator->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(PuzzleGenerator);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        label_2 = new QLabel(PuzzleGenerator);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        heightBox = new QSpinBox(PuzzleGenerator);
        heightBox->setObjectName(QString::fromUtf8("heightBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(heightBox->sizePolicy().hasHeightForWidth());
        heightBox->setSizePolicy(sizePolicy1);
        heightBox->setMinimumSize(QSize(50, 0));
        heightBox->setMinimum(3);
        heightBox->setMaximum(40);
        heightBox->setValue(10);

        horizontalLayout->addWidget(heightBox);

        label = new QLabel(PuzzleGenerator);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        widthBox = new QSpinBox(PuzzleGenerator);
        widthBox->setObjectName(QString::fromUtf8("widthBox"));
        widthBox->setMinimumSize(QSize(50, 0));
        widthBox->setMinimum(3);
        widthBox->setMaximum(40);
        widthBox->setValue(10);

        horizontalLayout->addWidget(widthBox);

        btn_generate = new QPushButton(PuzzleGenerator);
        btn_generate->setObjectName(QString::fromUtf8("btn_generate"));

        horizontalLayout->addWidget(btn_generate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_surrender = new QPushButton(PuzzleGenerator);
        btn_surrender->setObjectName(QString::fromUtf8("btn_surrender"));

        horizontalLayout->addWidget(btn_surrender);


        verticalLayout_2->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(PuzzleGenerator);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 473, 215));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        grid = new QGridLayout();
        grid->setObjectName(QString::fromUtf8("grid"));

        verticalLayout->addLayout(grid);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        retranslateUi(PuzzleGenerator);

        QMetaObject::connectSlotsByName(PuzzleGenerator);
    } // setupUi

    void retranslateUi(QWidget *PuzzleGenerator)
    {
        PuzzleGenerator->setWindowTitle(QApplication::translate("PuzzleGenerator", "Form", 0));
        label_2->setText(QApplication::translate("PuzzleGenerator", "Rows:", 0));
        label->setText(QApplication::translate("PuzzleGenerator", "Columns:", 0));
        btn_generate->setText(QApplication::translate("PuzzleGenerator", "Generate Puzzle", 0));
        btn_surrender->setText(QApplication::translate("PuzzleGenerator", "Give Up", 0));
    } // retranslateUi

};

namespace Ui {
    class PuzzleGenerator: public Ui_PuzzleGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUZZLEGENERATOR_H
