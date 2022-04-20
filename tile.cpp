#include "tile.h"
#include "ui_tile.h"

Tile::Tile(QString path, QString name, QString w, QString h, QWidget *parent) :
    path(path), name(name), QWidget(parent),
    ui(new Ui::Tile)
{
    ui->setupUi(this);

    width = w.toInt(NULL, 10);
    height = h.toInt(NULL, 10);

    ui->l_name->setText(name);
    ui->l_size->setText(w + "x" + h);
}

void Tile::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit click(path);
    }
}

QString Tile::getName() {
    return name;
}
int Tile::getWidth() {
    return width;
}
int Tile::getHeight() {
    return height;
}

bool Tile::compareName(Tile* t1, Tile* t2) {
    return t1->getName() < t2->getName();
}
bool Tile::compareSize(Tile* t1, Tile* t2) {
    return t1->getWidth() * t1->getHeight() < t2->getWidth() * t2->getHeight();
}

Tile::~Tile()
{
    delete ui;
}
