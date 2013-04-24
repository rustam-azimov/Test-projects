#include "airGun.h"

AirGun::AirGun(QGraphicsScene *scene) :
    base(new AirGunBase),
    turret(new AirGunTurret),
    currentRotation(-45),
    maxRotate(-20),
    minRotate(-70)
{
    scene->addItem(turret);
    scene->addItem(base);
    turret->setAngle(currentRotation);
}

AirGun::~AirGun()
{
    delete base;
    delete turret;
}

void AirGun::rotateTurret(int step)
{
    if (currentRotation > maxRotate)
        currentRotation = maxRotate;

    if (currentRotation < minRotate)
        currentRotation = minRotate;

    currentRotation += step;
    turret->setAngle(currentRotation);
}

void AirGun::shoot()
{
    turret->shoot();
}
