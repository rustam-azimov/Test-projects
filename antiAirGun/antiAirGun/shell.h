#ifndef SHELL_H
#define SHELL_H

#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsItem>
#include <QtGui/QPainter>
#include <QObject>

#include "plane.h"
#include "myConsts.h"

class Shell : public QGraphicsItem
{
public:
    Shell(int angle, int posX, int posY);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *GameWidget);

protected:
    void advance(int step);
    void setNewPos();
    void setNewRotation();

private:
    qreal deltaSpeed;
    int delay;

    int const speed;

    qreal currX;
    qreal currY;

    qreal const argument;

    qreal direction;
};

#endif // SHELL_H
