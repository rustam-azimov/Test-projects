#include "explosiveAnimation.h"

ExplosiveAnimation::ExplosiveAnimation() :
    scale(0.5),
    animation(new QLabel()),
    movie(new QMovie(":/plane/animation_explosive.gif"))
{
    animation->setMovie(movie);
    animation->setStyleSheet("background: transparent");
}

ExplosiveAnimation::~ExplosiveAnimation()
{
    delete animation;
    delete movie;
}

void ExplosiveAnimation::setPos(qreal x, qreal y)
{
    proxy->setPos(x, y + 30);
}

void ExplosiveAnimation::setScene(QGraphicsScene *pScene)
{
    movie->start();
    movie->setSpeed(180);
    proxy = pScene->addWidget(animation);
    proxy->setScale(scale);
    proxy->setRotation(-90);
}

void ExplosiveAnimation::start()
{
    animation->setVisible(true);
    movie->start();
    connect(movie, SIGNAL(finished()), this, SLOT(stop()));
}

void ExplosiveAnimation::stop()
{
    movie->stop();
    animation->setVisible(false);
}
