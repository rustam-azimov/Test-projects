#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

#include "plane.h"

class Player : public QObject
{
    Q_OBJECT
public:
    Player();
    
signals:
    void scoreChanged(int);
    void hpChanged(int);
    
public slots:
    void addScoreForPlane();
    void reduceHpFromPlane();

private:
    int score;

    int healthPoints;

    int const scoreForPlane;
    int const damageFromPlane;
    
};

#endif // PLAYER_H
