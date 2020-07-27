#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtMultimedia/QSound>

#include "gifAnimation.h"
#include "bomb.h"

class Plane : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Plane(qreal startX, qreal startY);
    ~Plane();

    void explosive();
    Bomb *myBomb;

signals:
    void planeHit();

protected:
    void advance(int step);
    void setNewPos();

private:
    void playExplosiveAnimation();

private:
    GifAnimation *animation;
    QSound soundExplosive;

    qreal const scale;

    bool isBombed;
    bool isBombOnScene;

    qreal currX;
    qreal currY;

    qreal height;
};

#endif // PLANE_H
