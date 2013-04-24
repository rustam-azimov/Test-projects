#include "shootAnimation.h"

ShootAnimation::ShootAnimation() :
    scale(0.7),
    isSceneAlreadySet(false),
    animation(new QLabel()),
    movie(new QMovie(":/gun/animation_shoot.gif"))
{
    animation->setMovie(movie);
    animation->setStyleSheet("background: transparent");
}

ShootAnimation::~ShootAnimation()
{
    delete animation;
    delete movie;
}

bool ShootAnimation::isSceneSet()
{
    return isSceneAlreadySet;
}

void ShootAnimation::setPos(qreal x, qreal y)
{
    proxy->setPos(x - (64 * scale) / 2 + 4,
                  y - (64 * scale) / 2 - 2);
}

void ShootAnimation::setScene(QGraphicsScene *pScene)
{
    isSceneAlreadySet = true;
    movie->start();
    proxy = pScene->addWidget(animation);
    proxy->setScale(scale);
}

void ShootAnimation::start()
{
    animation->setVisible(true);
    movie->start();
    connect(movie, SIGNAL(finished()), this, SLOT(stop()));
}

void ShootAnimation::stop()
{
    movie->stop();
    animation->setVisible(false);
}


