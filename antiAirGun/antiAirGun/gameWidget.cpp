#include "gameWidget.h"
#include "shell.h"

GameWidget::GameWidget(QWidget *parent) :
    QGraphicsView(parent),
    scene(new QGraphicsScene),
    player(new Player)
{
    scene->setSceneRect(0, 0, 768, 380);
    setScene(scene);
    scene->setBackgroundBrush(Qt::white);

    background = new QGraphicsPixmapItem(QPixmap(":/background.gif"));
    background->setPos(0, 328);
    scene->addItem(background);

    setText();

    army = new EnemyArmy(scene, player);
    airGun = new AirGun(scene);
}

GameWidget::~GameWidget()
{
    scene->clear();
    delete scene;
    delete player;
    delete army;
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    const int rotateStep = 2;
    switch (event->key())
    {
    case Qt::Key_Up:
    {
        airGun->rotateTurret(-rotateStep);
        break;
    }
    case Qt::Key_Down:
    {
        airGun->rotateTurret(rotateStep);
        break;
    }
    case Qt::Key_Space:
    {
        airGun->shoot();
        break;
    }
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

void GameWidget::setText()
{
    score = new QGraphicsTextItem;
    score->setHtml("<B>SCORE : 0</B>");
    score->setFont(QFont("Terminus"));
    score->setPos(645, 333);
    scene->addItem(score);

    QObject::connect(player, SIGNAL(scoreChanged(int)), this, SLOT(setNewScore(int)));

    healthPoints = new QGraphicsTextItem;
    healthPoints->setHtml("<B>HP : 5</B>");
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

