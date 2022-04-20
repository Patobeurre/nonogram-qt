#ifndef TILE_H
#define TILE_H

#include <QWidget>
#include <QMouseEvent>
#include <QString>
#include <QDebug>

namespace Ui {
class Tile;
}

class Tile : public QWidget
{
    Q_OBJECT

private:
    QString name;
    int width, height;
    QString path;
    Ui::Tile *ui;

    void mouseReleaseEvent(QMouseEvent *event) override;

public:
    explicit Tile(QString path, QString name, QString width, QString height, QWidget *parent = 0);
    ~Tile();

    QString getName();
    int getWidth();
    int getHeight();

    bool static compareName(Tile* t1, Tile* t2);
    bool static compareSize(Tile* t1, Tile* t2);

signals:
    void click(QString path);

};

#endif // TILE_H
