#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include <QtGui/QGraphicsPixmapItem>
#include <QSound>

#include "explosiveAnimation.h"
#include "bomb.h"

class Plane : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Plane(qreal startX, qreal startY);
    ~Plane() {
        delete myBomb;
        delete animation;
    }

    void explosive();
    Bomb *myBomb;

signals:
    void planeHit();

protected:
    void advance(int step);
    void setNewPos();

private:
    ExplosiveAnimation *animation;
    QSound soundExplosive;

    qreal const scale;

    bool bombWithMe;
    bool bombOnScene;

    qreal currX;
    qreal currY;

    qreal height;
};

#endif // PLANE_H
