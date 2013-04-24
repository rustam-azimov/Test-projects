#include "plane.h"

#include <qmath.h>


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
    QList<QGraphicsItem *> collidingWithShell = this->scene()->collidingItems(this);
    QList<QGraphicsItem *>::Iterator iter;
    for (iter = collidingWithShell.begin(); iter != collidingWithShell.end(); iter++)
    {
        QGraphicsItem *shell = *iter;
        if (shell->collidesWithItem(this))
        {            
            this->scene()->removeItem(shell);

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
