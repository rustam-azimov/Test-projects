#include "bomb.h"
#include "qmath.h"

Bomb::Bomb() :
    myFollowSpeed(bombStartSpeed),
    withPlane(true),
    animation(new ExplosiveAnimation),
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
    if (!withPlane)
    {
        followOnGun();
        QList<QGraphicsItem *> collidingWithBomb = this->scene()->collidingItems(this);
        QList<QGraphicsItem *>::Iterator iter;
        for (iter = collidingWithBomb.begin(); iter != collidingWithBomb.end(); iter++)
        {
            QGraphicsItem *airGunBase = *iter;
            if (airGunBase->collidesWithItem(this))
            {
                emit bombExploded();
                this->bombExplosive();
                soundExplosive.play();
                this->scene()->removeItem(this);
             }
         }
    }
}

void Bomb::bombExplosive()
{
    animation->setScene(this->scene());
    animation->setPos(this->scenePos().x(), this->scenePos().y());
    animation->start();
}

void Bomb::followOnGun()
{
    myFollowSpeed += bombGAcceleration;
    this->setPos(mapToScene(0, myFollowSpeed));
}

void Bomb::dropTheBomb()
{
    withPlane = false;
}
