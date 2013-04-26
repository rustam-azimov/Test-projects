#ifndef MYCONSTS_H
#define MYCONSTS_H

int const sceneWidth = 768;
int const sceneHeight = 380;

int const menuTextX = 5 * sceneWidth / 12; // main menu text x coordinate

int const menuLeftBulletX = menuTextX - 55; // start coordinates menuLeftBullet
int const menuRightBulletX = menuLeftBulletX + 155; // start coordinates menuRightBullet
int const menuBulletsY = (sceneHeight / 4) + 8;// start menu bulets Y coordinate
int const menuBulletsYDiff = sceneHeight / 8; // difference between main menu texts


qreal const myPi = 3.14159265359;
int const myGravity = 2000;
qreal const timerStepInSec = 0.04;
qreal const sqrTimerStepInSec = timerStepInSec * timerStepInSec;
int const timerStepInMSec = 40;

#endif // MYCONSTS_H
