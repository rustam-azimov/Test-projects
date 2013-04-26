#include "gameWidget.h"
#include "shell.h"

#include <QtAlgorithms>

GameWidget::GameWidget(QWidget *parent) :
    QGraphicsView(parent),
    scene(new QGraphicsScene),
    player(new Player),
    mainMenu(new MainMenu(scene)),
    isGameStarted(false),
    background(new QGraphicsPixmapItem(QPixmap(":/game/background.gif"))),
    gameOver(new QGraphicsPixmapItem(QPixmap(":/game/game_over.gif")))
{
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
    setScene(scene);
    scene->setBackgroundBrush(Qt::white);
    QObject::connect(player, SIGNAL(gameOver()),
                     this, SLOT(gameIsOver()));

    mainMenu->setMainMenu();
}

GameWidget::~GameWidget()
{
    delete airGun;
    delete player;
    delete army;
    delete mainMenu;
    delete scene;
}


void GameWidget::keyPressEvent(QKeyEvent *event)
{
    const int rotateStep = 2;
    switch (event->key())
    {
    case Qt::Key_Up:
    {
        if (isGameStarted)
        {
            airGun->rotateTurret(-rotateStep);
        }
        if(mainMenu->isMenuStarted)
        {
            mainMenu->setPosMenuBullets(-1);
        }
        break;
    }
    case Qt::Key_Down:
    {
        if (isGameStarted)
        {
            airGun->rotateTurret(rotateStep);
        }
        if(mainMenu->isMenuStarted)
        {
            mainMenu->setPosMenuBullets(1);
        }
        break;
    }
    case Qt::Key_Space:
    {
        if(isGameStarted)
        {
            airGun->shoot();
        }
        if(mainMenu->isMenuStarted)
        {
            switch(mainMenu->pushMenuText())
            {
            case 0:
            {
                startNewGame();
                break;
            }
            }
        }
        break;
    }
    default:
        QGraphicsView::keyPressEvent(event);
    }
}


void GameWidget::startNewGame()
{
    isGameStarted = true;

    background->setPos(0, 328);
    scene->addItem(background);

    setGameText();

    army = new EnemyArmy(scene, player);

    airGun = new AirGun(scene);
}


void GameWidget::setGameText()
{
    score = new QGraphicsTextItem;
    setNewScore(0);
    score->setFont(QFont("Terminus"));
    score->setPos(645, 333);
    scene->addItem(score);

    QObject::connect(player, SIGNAL(scoreChanged(int)), this, SLOT(setNewScore(int)));

    healthPoints = new QGraphicsTextItem;
    setNewHP(5);
    healthPoints->setFont(QFont("Terminus"));
    healthPoints->setPos(645, 303);
    scene->addItem(healthPoints);

    QObject::connect(player, SIGNAL(hpChanged(int)), this, SLOT(setNewHP(int)));
}

void GameWidget::setNewScore(int newScore)
{
    score->setHtml("<B>SCORE : " + QString::number(newScore) + "</B>");
}

void GameWidget::setNewHP(int newHp)
{
    healthPoints->setHtml("<B>HP : " + QString::number(newHp) + "</B>");
}

void GameWidget::gameIsOver()
{
    if (isGameStarted)
    {
        isGameStarted = false;
        scene->removeItem(airGun->base);
        scene->removeItem(airGun->turret);
        army->clear();

        gameOver->setPos(menuTextX, menuBulletsY +  menuBulletsYDiff);
        scene->addItem(gameOver);
    }

    //setMainMenu();// VERY BIG problems...
}


