#include "shell.h"

#include <qmath.h>
#include <QList>

Shell::Shell(int angle, int posX, int posY):
    delay(5),
    speed(300),
    currX(posX + 4),
    currY(posY - 2),
    argument((qAbs(angle) * myPi) / 180),
    direction(angle)
{
    deltaSpeed = 10 * timerStepInSec;
    setPos(currX, currY);
    setRotation(direction);
}

QRectF Shell::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(0 - adjust, 0 - adjust,
                  15 + adjust, 3 + adjust);
}

QPainterPath Shell::shape() const
{
    QPainterPath path;
    path.addRect(3, 0, 12, 3);
    return path;
}

void Shell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *GameWidget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(1, 1, 12, 3);
    painter->drawRect(13, 2, 3, 1);
}

void Shell::setNewPos()
{
    currX = currX +
             (speed * timerStepInSec * qCos(argument));
    currY = currY -
             ((speed * timerStepInSec * qSin(argument)) -
              (10 * sqrTimerStepInSec / 2));
}

void Shell::setNewRotation()
{
    deltaSpeed = deltaSpeed + 10 * timerStepInSec;
    direction = -qAtan(((speed * qSin(argument)) -
                       deltaSpeed) /
                       (speed * qCos(argument)))
                * (180 / myPi);
}

void Shell::advance(int step)
{
    if (!step)
        return;

    if (delay > 0)
        delay--;

    setNewPos();
    setNewRotation();
    setPos(currX, currY);
    setRotation(direction);
}


