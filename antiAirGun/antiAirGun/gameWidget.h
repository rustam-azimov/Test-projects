#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QtGui/QGraphicsTextItem>
#include <QtGui/QGraphicsView>
#include <QtGui/QKeyEvent>

#include "player.h"
#include "airGun.h"
#include "enemyArmy.h"

// Стартовое меню.
// Следующий уровень.
// Бос???
class GameWidget : public QGraphicsView
{
    Q_OBJECT
public:
    GameWidget(QWidget *parent = 0);
    QGraphicsScene *scene;
    ~GameWidget();
    
protected:
    void setText();
    void keyPressEvent(QKeyEvent *event);

private:
    Player *player;
    AirGun *airGun;
    EnemyArmy *army;
    QGraphicsTextItem *score;
    QGraphicsTextItem *healthPoints;
    QGraphicsPixmapItem *background;

private slots:
    void setNewScore(int newScore);
    void setNewHP(int newHp);
};

#endif // GAMEWIDGET_H
