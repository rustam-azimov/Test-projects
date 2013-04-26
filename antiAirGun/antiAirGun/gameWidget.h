#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QtGui/QGraphicsTextItem>
#include <QtGui/QGraphicsView>
#include <QtGui/QKeyEvent>

#include "player.h"
#include "airGun.h"
#include "enemyArmy.h"
#include "mainMenu.h"


// Стартовое меню.
// Следующий уровень.
// Бос???



class GameWidget : public QGraphicsView
{
    Q_OBJECT
public:
    GameWidget(QWidget *parent = 0);
    QGraphicsScene *scene;
    Player *player;
    ~GameWidget();
    
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    bool isGameStarted;
    AirGun *airGun;
    EnemyArmy *army;
    MainMenu *mainMenu;
    QGraphicsTextItem *score;
    QGraphicsTextItem *healthPoints;
    QGraphicsPixmapItem *background;
    QGraphicsPixmapItem *gameOver;

    void startNewGame();
    void setGameText();

private slots:
    void setNewScore(int newScore);
    void setNewHP(int newHp);
    void gameIsOver();
};

#endif // GAMEWIDGET_H
