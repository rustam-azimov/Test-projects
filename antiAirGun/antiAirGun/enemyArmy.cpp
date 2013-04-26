#include "enemyArmy.h"

#include <QTimer>
#include <QTime>
#include <QMutableListIterator>

EnemyArmy::EnemyArmy(QGraphicsScene *scene, Player *player) :
    planeList(new QList<Plane *>),
    pScene(scene),
    pPlayer(player)
{
    qsrand(QTime::currentTime().msec());

    timerToAdd = new QTimer;
    QObject::connect(timerToAdd, SIGNAL(timeout()), this, SLOT(createPlane()));
    timerToAdd->start(3500);

    timerToRemove = new QTimer;
    QObject::connect(timerToRemove, SIGNAL(timeout()), this, SLOT(removeExtraPlanes()));
    timerToRemove->start(5000);
}

EnemyArmy::~EnemyArmy()
{
    clear();
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
    QMutableListIterator<Plane *> i(*planeList);

     while (i.hasNext())
     {
         Plane* plane = i.next();
         if ((plane->scenePos().x() < -300) || (plane->scene() == NULL))
         {
             i.remove();
             delete plane;
         }
     }
}

void EnemyArmy::clear()
{
    QObject::disconnect(timerToAdd, SIGNAL(timeout()), this, SLOT(createPlane()));
    QObject::disconnect(timerToRemove, SIGNAL(timeout()), this, SLOT(removeExtraPlanes()));
    while (!planeList->isEmpty())
    {
        delete planeList->first();
        planeList->removeFirst();
    }
}

