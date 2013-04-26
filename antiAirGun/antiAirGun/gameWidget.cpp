#include "gameWidget.h"
#include "shell.h"

GameWidget::GameWidget(QWidget *parent) :
    QGraphicsView(parent),
    scene(new QGraphicsScene),
    player(new Player),
    isGameStarted(false),
    background(new QGraphicsPixmapItem(QPixmap(":/background.gif"))),
    menuBulletsStatus(0)
{
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
    setScene(scene);
    scene->setBackgroundBrush(Qt::white);
    mainMenuNewGame = new QGraphicsTextItem;
    mainMenuRecords = new QGraphicsTextItem;
    mainMenuHelp = new QGraphicsTextItem;
    menuLeftBullet = new QGraphicsPixmapItem;
    menuRightBullet = new QGraphicsPixmapItem;
    setMainMenu();
}

GameWidget::~GameWidget()
{
    delete airGun;
    delete player;
    delete army;
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
        } else
        {
            setPosMenuBullets(menuBulletsStatus - 1);
        }
        break;
    }
    case Qt::Key_Down:
    {
        if (isGameStarted)
        {
            airGun->rotateTurret(rotateStep);
        } else
        {
            setPosMenuBullets(menuBulletsStatus + 1);
        }
        break;
    }
    case Qt::Key_Space:
    {
        if(isGameStarted)
        {
            airGun->shoot();
        } else
        {
            pushMenuText();
        }
        break;
    }
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

void GameWidget::setMainMenu()
{

    setMainMenuText(mainMenuNewGame, menuTextX,
                    (sceneHeight / 4), "<big><b><tt>New_Game</tt></b></big>");

    setMainMenuText(mainMenuRecords, menuTextX,
                    (3 * sceneHeight / 8), "<big><b><tt>Records!</tt></b></big>");
    setMainMenuText(mainMenuHelp, menuTextX,
                    sceneHeight / 2, "<big><b><tt>??Help??</tt></b></big>");

    menuLeftBullet->setPixmap(QPixmap(":/gun/leftBullet.gif"));
    menuRightBullet->setPixmap(QPixmap(":/gun/rightBullet.gif"));
    setPosMenuBullets(0);
    scene->addItem(menuLeftBullet);
    scene->addItem(menuRightBullet);

}

void GameWidget::setMainMenuText(QGraphicsTextItem *mainMenuText, int posX,
                                 int posY, QString text)
{
    mainMenuText->setHtml(text);
    mainMenuText->setFont(QFont("Terminus"));
    mainMenuText->setPos(posX, posY);
    scene->addItem(mainMenuText);
}


void GameWidget::setPosMenuBullets(int changedStatus)
{
    menuBulletsStatus = changedStatus;// 0 - New Game; 1 - Records; 2 - Help;
    if (menuBulletsStatus > 2)//after help
        menuBulletsStatus = 0;// is new game
    if (menuBulletsStatus < 0) // before new game
        menuBulletsStatus = 2; // is help
    menuLeftBullet->setPos(menuLeftBulletX, menuBulletsY + menuBulletsStatus * menuBulletsYDiff);
    menuRightBullet->setPos(menuRightBulletX, menuBulletsY + menuBulletsStatus * menuBulletsYDiff);
}



void GameWidget::pushMenuText()
{
    switch (menuBulletsStatus)
    {
    case 0:
    {
        scene->clear();
        menuBulletsStatus = 0;
        startNewGame();
        break;
    }
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


