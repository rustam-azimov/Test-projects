#include "plane.h"

#include <qmath.h>
#include <QMutableListIterator>

Plane::Plane(qreal startX, qreal startY):
    animation(new ExplosiveAnimation),
    soundExplosive(":/plane/sound_plane_explosive.wav"), // Ну и наконец, тут не подключает
    scale(0.3),
    currX(startX),
    currY(startY),
    height(startY),
    bombWithMe(true),
    bombOnScene(false)
{
    soundExplosive.setLoops(1);
    this->setPixmap(QPixmap(":/plane/plane.gif"));
    this->setScale(scale);
    this->setPos(currX, currY);
    myBomb = new Bomb();
    myBomb->setPos(currX + bombX, currY + bombY);

}

Plane::~Plane()
{
    delete myBomb;
    delete animation;
}

void Plane::explosive()
{
    animation->setScene(this->scene());
    animation->setPos(currX, currY);
    animation->start();
}

void Plane::setNewPos()
{
    currX = currX - 3;
    currY = height - 20 * qCos(currX / 50);
}

void Plane::advance(int step)
{
    if (!step)
        return;

    if (!bombOnScene)
    {
        bombOnScene = true;
        this->scene()->addItem(myBomb);
    }
    QList<QGraphicsItem *> collidingWithPlane = this->scene()->collidingItems(this);

    QMutableListIterator<QGraphicsItem *> i(collidingWithPlane);

    while (i.hasNext())
    {
        QGraphicsItem *plane = i.next();
        if (plane->collidesWithItem(this))
        {            
            this->scene()->removeItem(plane);

            emit planeHit();

            this->explosive();
            if (bombWithMe)
            {
                this->scene()->removeItem(this->myBomb);
            }
            this->scene()->removeItem(this);

            soundExplosive.play();
        }
    }

    setNewPos();
    setPos(currX, currY);
    if ((currX + bombX <= bombDropXCoordinate) && (bombWithMe))
    {
        myBomb->dropTheBomb();
        bombWithMe = false;
    } else if (bombWithMe)
    {
        myBomb->setPos(currX + bombX, currY + bombY);
    }
}
