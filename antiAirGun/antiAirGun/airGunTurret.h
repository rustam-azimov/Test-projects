#ifndef AIRGUNTURRET_H
#define AIRGUNTURRET_H

#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsScene>
#include <QtMultimedia/QSound>
#include <QList>
#include <QObject>

#include "gifAnimation.h"

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

protected:
    void clear();

private slots:
    void canShoot();
    void removeExtraShells();

private:
    void playShootAnimation();

private:
    QList<QGraphicsItem *> *shellList;
    GifAnimation *animation;
    QSound soundShoot;

    qreal const animationScale;

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
