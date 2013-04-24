#ifndef AIRGUNTURRET_H
#define AIRGUNTURRET_H

#include <QtGui/QGraphicsPixmapItem>
#include <QtGui/QGraphicsScene>
#include <QSound>
#include <QList>
#include <QObject>

#include "shootAnimation.h"

/**
 * @file airGunTurret.h
 *
 * Implementation of AirGunTurret class.
 * This is a moving part of AntiAirGun.
 *  Vovka ti tut ok?
 */

class AirGunTurret : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    AirGunTurret();
    ~AirGunTurret();

    void setAngle(int angle);
    void upgradeBarrelCoordinates();
    void shoot();

private slots:
    void canShoot();

private:
    QList<QGraphicsItem *> *shellList;
    ShootAnimation *animation;
    QSound soundShoot;

    int const rotationCenterLocalX;
    int const rotationCenterLocalY;
    qreal const size;

    int const rotationCenterAbsoluteX;
    int const rotationCenterAbsoluteY;

    int const gunBarrelLength;

    int barrelX;
    int barrelY;

    bool canShootNow;

    int angle;
};

#endif // AIRGUNTURRET_H
