#include "airGunTurret.h"

#include <qmath.h>
#include <QTimer>

#include "shell.h"

AirGunTurret::AirGunTurret() :
    shellList(new QList<QGraphicsItem *>),
    animation(new ShootAnimation),
    soundShoot(":/gun/sound_shoot2.wav"), // ��� ��� �������� �� ����������!
    rotationCenterLocalX(70),
    rotationCenterLocalY(31),
    size(0.3),
    rotationCenterAbsoluteX(45),
    rotationCenterAbsoluteY(342),
    gunBarrelLength(96),
    canShootNow(true),
    angle(-30)
{
    soundShoot.setLoops(1);
    this->setPixmap(QPixmap(":/gun/gun.gif"));
    this->setVisible(true);
    this->scale(size, size);
    this->setPos(25, 330);
    this->setTransformOriginPoint(QPointF(rotationCenterLocalX, rotationCenterLocalY));
    this->setRotation(angle);

    QTimer *timerToRemove = new QTimer;
    QObject::connect(timerToRemove, SIGNAL(timeout()), this, SLOT(removeExtraShells()));
    timerToRemove->start(5000);
}

AirGunTurret::~AirGunTurret()
{
    shellList->clear();
    delete shellList;
    delete animation;
}

void AirGunTurret::setAngle(int angle)
{
    this->setRotation(angle);
    this->angle = angle;
}

void AirGunTurret::upgradeBarrelCoordinates()
{
    double argument = (qAbs(angle) * myPi) / 180;
    barrelX = rotationCenterAbsoluteX + (int)(gunBarrelLength * qCos(argument));
    barrelY = rotationCenterAbsoluteY - (int)(gunBarrelLength * qSin(argument));
}

void AirGunTurret::shoot()
{
    if (!canShootNow)
        return;

    upgradeBarrelCoordinates();

    Shell *shell = new Shell(angle, barrelX, barrelY);
    shellList->prepend(shell);
    this->scene()->addItem(shell);

    if (!animation->isSceneSet())
        animation->setScene(this->scene());

    animation->setPos(barrelX, barrelY);
    animation->start();

    soundShoot.play();

    canShootNow = false;
    QTimer::singleShot(2000, this, SLOT(canShoot()));
}

void AirGunTurret::canShoot()
{
    canShootNow = true;
}

void AirGunTurret::removeExtraShells()
{
    QMutableListIterator<QGraphicsItem *> i(*shellList);

     while (i.hasNext())
     {
         QGraphicsItem* shell = i.next();
         if ((shell->scenePos().x() > 800) || (shell->scene() == NULL))
         {
             i.remove();
             delete shell;
         }
     }
}





