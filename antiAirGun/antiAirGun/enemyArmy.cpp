#include "enemyArmy.h"

#include <QTimer>
#include <QTime>
#include <QMutableListIterator>

EnemyArmy::EnemyArmy(QGraphicsScene *scene, Player *player) :
    planeList(new QList<QGraphicsItem *>),
    pScene(scene),
    pPlayer(player)
{
    qsrand(QTime::currentTime().msec());

    timerToAdd = new QTimer;
    QObject::connect(timerToAdd, SIGNAL(timeout()), this, SLOT(createPlane()));
    timerToAdd->start(3500);

    timerToRemove = new QTimer;
    QObject::connect(timerToRemove, SIGNAL(timeout()), this, SLOT(removeExtraPlanes()));
    timerToRemove->start(5500);

    QObject::connect(pPlayer, SIGNAL(gameOver()), this, SLOT(stopWar()));
}

EnemyArmy::~EnemyArmy()
{
    planeList->clear();
    delete planeList;
    delete timerToRemove;
    delete timerToAdd;
}

void EnemyArmy::createPlane()
{
    Plane *plane = new Plane(startX, height[qrand() % 3]);
    pScene->addItem(plane);

    QObject::connect(plane, SIGNAL(planeHit()), pPlayer, SLOT(addScoreForPlane()));

    QObject::connect(plane->myBomb, SIGNAL(bombExploded()), pPlayer, SLOT(reduceHpFromPlane()));

    planeList->prepend(plane);
}

void EnemyArmy::removeExtraPlanes()
{
    QMutableListIterator<QGraphicsItem *> i(*planeList);

     while (i.hasNext())
     {
         QGraphicsItem* plane = i.next();
         if (plane->scene() == 0)
         {
             i.remove();
         }
         if (plane->scenePos().x() < -300)
         {
             pScene->removeItem(plane);
             i.remove();
             delete plane;
         }
     }
}

void EnemyArmy::stopWar()
{
    planeList->clear();
    QObject::disconnect(timerToAdd, SIGNAL(timeout()), this, SLOT(createPlane()));
    QObject::disconnect(timerToRemove, SIGNAL(timeout()), this, SLOT(removeExtraPlanes()));
}
