#include "bomb.h"
#include <qmath.h>

#include <QMutableListIterator>

Bomb::Bomb() :
    myFollowSpeed(bombStartSpeed),
    isWithPlane(true),
    animation(new GifAnimation(":/plane/animation_bomb_explosive.gif")),
    soundExplosive(":/plane/sound_plane_explosive.wav") // и тут не подключает
{
    soundExplosive.setLoops(1);
    this->setPixmap(QPixmap(":/plane/bomb.gif"));
    this->scale(bombScale, bombScale);
}

void Bomb::advance(int step)
{
    if (!step)
        return;
    if (!isWithPlane)
    {
        followOnGun();
        QList<QGraphicsItem *> collidingWithBomb = this->scene()->collidingItems(this);

        QMutableListIterator<QGraphicsItem *> i(collidingWithBomb);

        while (i.hasNext())
        {
            QGraphicsItem *airGunBase = i.next();
            if (airGunBase->collidesWithItem(this))
            {
                playExplosiveAnimation();

                emit bombExploded();
                soundExplosive.play();
                this->scene()->removeItem(this);
             }
         }
    }
}

void Bomb::playExplosiveAnimation()
{
    animation->setScale(0.6);

    animation->setSpeed(150);
    if (!animation->isSceneSet())
        animation->setOnScene(this->scene());

    animation->setPos(20, 240);

    animation->start();
}

void Bomb::followOnGun()
{
    myFollowSpeed += bombGAcceleration;
    this->setPos(mapToScene(0, myFollowSpeed));
}

void Bomb::dropTheBomb()
{
    isWithPlane = false;
}
