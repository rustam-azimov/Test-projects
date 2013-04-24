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

protected:
    void atack();

private:
    QList<QGraphicsItem *> *planeList;
    QGraphicsScene *pScene;
    Player *pPlayer;

public slots:
    void createPlane();
    void removeExtraPlanes();
};

#endif // ENEMYARMY_H
