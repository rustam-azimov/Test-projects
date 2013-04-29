#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QtGui/QGraphicsTextItem>
#include <QString>

class MainMenu
{
public:
    MainMenu(QGraphicsScene* scene);
    bool isMenuStarted;
    void setMainMenu();
    void setPosMenuBullets(int diffStatus);
    int pushMenuText();
private:
    QGraphicsScene* pScene;
    QGraphicsTextItem *mainMenuNewGame;
    QGraphicsTextItem *mainMenuRecords;
    QGraphicsTextItem *mainMenuHelp;
    QGraphicsPixmapItem *background;
    QGraphicsPixmapItem *gameOver;
    QGraphicsPixmapItem *menuLeftBullet;
    QGraphicsPixmapItem *menuRightBullet;
    int menuBulletsStatus;

    void setMainMenuText(QGraphicsTextItem *mainMenuText, int posX, int posY, QString text);
};

#endif // MAINMENU_H
