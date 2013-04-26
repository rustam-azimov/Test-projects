#ifndef TURRET_H
#define TURRET_H

#include <QGraphicsItem>

#include "airGunBase.h"
#include "airGunTurret.h"

/**
 * @file airGun.h
 *
 * Реализация класса AirGun.
 * Содержит все необходимое для создания и управления турелью.
 */

// Умирает от 5 бомб.
class AirGun
{
public:
    AirGun(QGraphicsScene *scene);
    ~AirGun();

    void rotateTurret(int step);
    void shoot();
    AirGunBase *base;
    AirGunTurret *turret;

protected:
    int currentRotation;

    int const maxRotate;
    int const minRotate;
};

#endif // TURRET_H
