/********************************************************************************
** Form generated from reading UI file 'tile.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILE_H
#define UI_TILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tile
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *l_name;
    QLabel *l_size;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Tile)
    {
        if (Tile->objectName().isEmpty())
            Tile->setObjectName(QString::fromUtf8("Tile"));
        Tile->resize(100, 100);
        Tile->setMinimumSize(QSize(100, 100));
        Tile->setMaximumSize(QSize(100, 100));
        verticalLayout = new QVBoxLayout(Tile);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        l_name = new QLabel(Tile);
        l_name->setObjectName(QString::fromUtf8("l_name"));
        l_name->setMaximumSize(QSize(100, 100));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        l_name->setFont(font);
        l_name->setScaledContents(false);
        l_name->setAlignment(Qt::AlignCenter);
        l_name->setWordWrap(true);

        verticalLayout->addWidget(l_name);

        l_size = new QLabel(Tile);
        l_size->setObjectName(QString::fromUtf8("l_size"));
        l_size->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(l_size);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Tile);

        QMetaObject::connectSlotsByName(Tile);
    } // setupUi

    void retranslateUi(QWidget *Tile)
    {
        Tile->setWindowTitle(QApplication::translate("Tile", "Form", 0));
        l_name->setText(QApplication::translate("Tile", "Name", 0));
        l_size->setText(QApplication::translate("Tile", "size", 0));
    } // retranslateUi

};

namespace Ui {
    class Tile: public Ui_Tile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILE_H
