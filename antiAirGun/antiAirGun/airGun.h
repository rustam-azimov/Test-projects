#ifndef TURRET_H
#define TURRET_H

#include <QGraphicsItem>

#include "airGunBase.h"
#include "airGunTurret.h"

/**
 * @file airGun.h
 *
 * ���������� ������ AirGun.
 * �������� ��� ����������� ��� �������� � ���������� �������.
 */


class AirGun
{
public:
    AirGun(QGraphicsScene *scene);

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
