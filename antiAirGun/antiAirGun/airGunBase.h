#ifndef AIRGUNBASE_H
#define AIRGUNBASE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

/**
 * @file airGunBase.h
 *
 * Implementation of AirGunBase class.
 * Contained base of AirGun. This scale = 0.3 and pos(10, 340).
 * This is a fixed part of AntiAirGun.
 */

class AirGunBase : public QGraphicsPixmapItem
{
public:
    AirGunBase() :
        scale(0.3)
    {
        this->setPixmap(QPixmap(":/gun/base.gif"));
        this->setScale(scale);
        this->setPos(10, 340);
    }

private:
    double const scale;
};

#endif // AIRGUNBASE_H
