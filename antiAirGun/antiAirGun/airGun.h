#ifndef TURRET_H
#define TURRET_H

#include <QGraphicsItem>

#include "airGunBase.h"
#include "airGunTurret.h"

/**
 * @file airGun.h
 *
 * Implementation of AirGun class.
 * Contained all to create and rule the turret.
 */

// ������� �� 5 ����.
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
