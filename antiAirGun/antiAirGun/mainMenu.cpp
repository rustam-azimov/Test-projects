#include "mainMenu.h"
#include "myConsts.h"

MainMenu::MainMenu(QGraphicsScene* scene) :
    pScene(scene),
    isMenuStarted(false),
    menuBulletsStatus(0)
{
    mainMenuNewGame = new QGraphicsTextItem;
    mainMenuRecords = new QGraphicsTextItem;
    mainMenuHelp = new QGraphicsTextItem;
    menuLeftBullet = new QGraphicsPixmapItem;
    menuRightBullet = new QGraphicsPixmapItem;
}

MainMenu::~MainMenu()
{
    delete mainMenuNewGame;
    delete mainMenuRecords;
    delete mainMenuHelp;
    delete menuLeftBullet;
    delete menuRightBullet;
}

void MainMenu::setMainMenu()
{
    isMenuStarted = true;
    setMainMenuText(mainMenuNewGame, menuTextX,
                    (sceneHeight / 4), "<big><b><tt>New_Game</tt></b></big>");

    setMainMenuText(mainMenuRecords, menuTextX,
                    (3 * sceneHeight / 8), "<big><b><tt>Records!</tt></b></big>");
    setMainMenuText(mainMenuHelp, menuTextX,
                    sceneHeight / 2, "<big><b><tt>??Help??</tt></b></big>");

    menuLeftBullet->setPixmap(QPixmap(":/gun/leftBullet.gif"));
    menuRightBullet->setPixmap(QPixmap(":/gun/rightBullet.gif"));
    setPosMenuBullets(0);
    pScene->addItem(menuLeftBullet);
    pScene->addItem(menuRightBullet);
}

void MainMenu::setPosMenuBullets(int diffStatus)
{
    menuBulletsStatus += diffStatus;// 0 - New Game; 1 - Records; 2 - Help;
    if (menuBulletsStatus > 2)//after help
        menuBulletsStatus = 0;// is new game
    if (menuBulletsStatus < 0) // before new game
        menuBulletsStatus = 2; // is help
    menuLeftBullet->setPos(menuLeftBulletX, menuBulletsY + menuBulletsStatus * menuBulletsYDiff);
    menuRightBullet->setPos(menuRightBulletX, menuBulletsY + menuBulletsStatus * menuBulletsYDiff);
}

void MainMenu::setMainMenuText(QGraphicsTextItem *mainMenuText, int posX, int posY, QString text)
{
    mainMenuText->setHtml(text);
    mainMenuText->setFont(QFont("Terminus"));
    mainMenuText->setPos(posX, posY);
    pScene->addItem(mainMenuText);
}

int MainMenu::pushMenuText()
{
    switch (menuBulletsStatus)
    {
    case 0:
    {
        pScene->clear();
        menuBulletsStatus = 0;
        isMenuStarted = false;
        return 0;
        //startNewGame
    }
    }
}
