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

    QTimer *timerToAdd = new QTimer;
    QObject::connect(timerToAdd, SIGNAL(timeout()), this, SLOT(createPlane()));
    timerToAdd->start(3500);

    QTimer *timerToRemove = new QTimer;
    QObject::connect(timerToRemove, SIGNAL(timeout()), this, SLOT(removeExtraPlanes()));
    timerToRemove->start(3500);
}

EnemyArmy::~EnemyArmy()
{
    planeList->clear();
    delete planeList;
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
         if ((plane->scenePos().x() < -100) || (plane->scene() == NULL))
         {
             i.remove();
             delete plane;
         }
     }
}
