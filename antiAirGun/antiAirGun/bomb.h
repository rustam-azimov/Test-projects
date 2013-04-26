#ifndef BOMB_H
#define BOMB_H

#include <QObject>

#include <QGraphicsPixmapItem>
#include "explosiveAnimation.h"
#include "QSound"

/**
 * @file airGun.h
 *
 * Implementation of Bomb class.
 * Object of this class it's item(bomb) which fly with
 * himself plane with local coordinates(in plane's coordinates) bombX = 34, bombY = 20,
 * and when it cross bombDropXCoordinate = 42, it fall on antiAirGun
 * with bombStartSpeed = 5, and bombGAcceleration = 9.81 * 0.04.
 */

/// 0.04 - it's timer rate.
qreal const bombGAcceleration = 9.81 * 0.04;
qreal const bombStartSpeed = 5;

int const bombDropXCoordinate = 42;

int const bombX = 34;
int const bombY = 20;

double const bombScale = 0.3;
/// @class Bomb
class Bomb : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT

public:
    Bomb();
    ~Bomb()
    {
        delete animation;
    }
    /// true while bomb fly with plane.
    bool isWithPlane;
    /// called when bomb cross bombDropXCoordinate = 42.
    void dropTheBomb();
    /// called when bomb touch with smth (can only be gun).
    void bombExplosive();

signals:
    /// emited when called bombExplosive().
    void bombExploded();

protected:
    /// do nothing while bool withPlane = true. And call followOnGun() otherwise.
    void advance(int step);
private:
    /// current follow speed, used only when withPlane = false.
    qreal myFollowSpeed;
    ExplosiveAnimation *animation;
    QSound soundExplosive;
    /// increase myFollowSpeed on bombGAcceleration and move down on myFollowSpeed.
    void followOnGun();

};

#endif // BOMB_H
