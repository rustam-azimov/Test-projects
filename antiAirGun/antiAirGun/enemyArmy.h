#ifndef ENEMYARMY_H
#define ENEMYARMY_H

#include <QList>
#include <QObject>
#include <QtGui/QGraphicsScene>

#include "plane.h"
#include "player.h"

int const startX = 785;
int const height[3] = {25, 75, 125};

class EnemyArmy : public QObject
{
    Q_OBJECT
public:
    EnemyArmy(QGraphicsScene *scene, Player *player);
    ~EnemyArmy();
    QList<QGraphicsItem *> *planeList;

protected:
    void atack();

private:
    QGraphicsScene *pScene;
    Player *pPlayer;
    QTimer *timerToRemove;
    QTimer *timerToAdd;

public slots:
    void createPlane();
    void removeExtraPlanes();
    void stopWar();
};

#endif // ENEMYARMY_H
