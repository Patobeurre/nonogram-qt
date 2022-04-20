/********************************************************************************
** Form generated from reading UI file 'puzzlecreator.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUZZLECREATOR_H
#define UI_PUZZLECREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PuzzleCreator
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *top;
    QLabel *label_2;
    QSpinBox *heightBox;
    QLabel *label;
    QSpinBox *widthBox;
    QPushButton *btn_generate;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *grid;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *txt_name;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_finalize;

    void setupUi(QWidget *PuzzleCreator)
    {
        if (PuzzleCreator->objectName().isEmpty())
            PuzzleCreator->setObjectName(QString::fromUtf8("PuzzleCreator"));
        PuzzleCreator->resize(679, 389);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PuzzleCreator->sizePolicy().hasHeightForWidth());
        PuzzleCreator->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(PuzzleCreator);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        top = new QHBoxLayout();
        top->setObjectName(QString::fromUtf8("top"));
        label_2 = new QLabel(PuzzleCreator);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        top->addWidget(label_2);

        heightBox = new QSpinBox(PuzzleCreator);
        heightBox->setObjectName(QString::fromUtf8("heightBox"));
        heightBox->setMinimumSize(QSize(50, 0));
        heightBox->setMinimum(3);
        heightBox->setMaximum(50);
        heightBox->setValue(10);

        top->addWidget(heightBox);

        label = new QLabel(PuzzleCreator);
        label->setObjectName(QString::fromUtf8("label"));

        top->addWidget(label);

        widthBox = new QSpinBox(PuzzleCreator);
        widthBox->setObjectName(QString::fromUtf8("widthBox"));
        widthBox->setMinimumSize(QSize(50, 0));
        widthBox->setMinimum(3);
        widthBox->setMaximum(50);
        widthBox->setValue(10);

        top->addWidget(widthBox);

        btn_generate = new QPushButton(PuzzleCreator);
        btn_generate->setObjectName(QString::fromUtf8("btn_generate"));

        top->addWidget(btn_generate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        top->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(top);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollArea = new QScrollArea(PuzzleCreator);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(6);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(300, 0));
        scrollArea->setAutoFillBackground(false);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 492, 332));
        scrollAreaWidgetContents->setAutoFillBackground(true);
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        grid = new QGridLayout();
        grid->setObjectName(QString::fromUtf8("grid"));

        horizontalLayout_2->addLayout(grid);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        line = new QFrame(PuzzleCreator);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_3 = new QLabel(PuzzleCreator);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        txt_name = new QLineEdit(PuzzleCreator);
        txt_name->setObjectName(QString::fromUtf8("txt_name"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(txt_name->sizePolicy().hasHeightForWidth());
        txt_name->setSizePolicy(sizePolicy2);
        txt_name->setMinimumSize(QSize(150, 0));

        verticalLayout->addWidget(txt_name);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_finalize = new QPushButton(PuzzleCreator);
        btn_finalize->setObjectName(QString::fromUtf8("btn_finalize"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_finalize->sizePolicy().hasHeightForWidth());
        btn_finalize->setSizePolicy(sizePolicy3);
        btn_finalize->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(btn_finalize, 0, Qt::AlignRight);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(PuzzleCreator);

        QMetaObject::connectSlotsByName(PuzzleCreator);
    } // setupUi

    void retranslateUi(QWidget *PuzzleCreator)
    {
        PuzzleCreator->setWindowTitle(QApplication::translate("PuzzleCreator", "Form", 0));
        label_2->setText(QApplication::translate("PuzzleCreator", "Rows:", 0));
        label->setText(QApplication::translate("PuzzleCreator", "Columns:", 0));
        btn_generate->setText(QApplication::translate("PuzzleCreator", "Generate", 0));
        label_3->setText(QApplication::translate("PuzzleCreator", "Name:", 0));
        btn_finalize->setText(QApplication::translate("PuzzleCreator", "Finalize", 0));
    } // retranslateUi

};

namespace Ui {
    class PuzzleCreator: public Ui_PuzzleCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUZZLECREATOR_H
