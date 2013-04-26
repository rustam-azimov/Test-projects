#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QtGui/QGraphicsTextItem>
#include <QtGui/QGraphicsView>
#include <QtGui/QKeyEvent>
#include <QString>

#include "player.h"
#include "airGun.h"
#include "enemyArmy.h"


// Стартовое меню.
// Следующий уровень.
// Бос???

int const sceneWidth = 768;
int const sceneHeight = 380;

int const menuTextX = 5 * sceneWidth / 12; // main menu text x coordinate

int const menuLeftBulletX = menuTextX - 55; // start coordinates menuLeftBullet
int const menuRightBulletX = menuLeftBulletX + 155; // start coordinates menuRightBullet
int const menuBulletsY = (sceneHeight / 4) + 8;// start menu bulets Y coordinate
int const menuBulletsYDiff = sceneHeight / 8; // difference between main menu texts

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
    bool isMenuStarted;
    AirGun *airGun;
    EnemyArmy *army;
    QGraphicsTextItem *score;
    QGraphicsTextItem *healthPoints;
    QGraphicsTextItem *mainMenuNewGame;
    QGraphicsTextItem *mainMenuRecords;
    QGraphicsTextItem *mainMenuHelp;
    QGraphicsPixmapItem *background;
    QGraphicsPixmapItem *gameOver;
    QGraphicsPixmapItem *menuLeftBullet;
    QGraphicsPixmapItem *menuRightBullet;
    int menuBulletsStatus;
    void setMainMenu();
    void setGameText();
    void setPosMenuBullets(int changedStatus);
    void setMainMenuText(QGraphicsTextItem *mainMenuText, int posX, int posY, QString text);
    void pushMenuText();
    void startNewGame();

private slots:
    void setNewScore(int newScore);
    void setNewHP(int newHp);
    void gameIsOver();
};

#endif // GAMEWIDGET_H
