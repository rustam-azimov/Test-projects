#include "gifAnimation.h"

GifAnimation::GifAnimation(const QString &fileName) :
    scale(GifAnimationConsts::standardScale),
    isSceneAlreadySet(false),
    currSpeed(GifAnimationConsts::standardSpeed),
    animation(new QLabel()),
    movie(new QMovie(fileName))
{
    animation->setMovie(movie);
    animation->setStyleSheet("background: transparent");
}

GifAnimation::~GifAnimation()
{
    delete animation;
    delete movie;
}

bool GifAnimation::isSceneSet() const
{
    return isSceneAlreadySet;
}

void GifAnimation::setPos(qreal x, qreal y)
{
    proxy->setPos(x, y);
}

void GifAnimation::setOnScene(QGraphicsScene *pScene)
{
    isSceneAlreadySet = true;
    movie->setSpeed(currSpeed);
    movie->start();
    proxy = pScene->addWidget(animation);
    proxy->setScale(scale);
}

void GifAnimation::setScale(const qreal &mScale)
{
    if (mScale > 0)
        this->scale = mScale;
    else
        this->scale = GifAnimationConsts::standardScale;
}

void GifAnimation::setSpeed(const int &speed)
{
    if (speed > 0)
        currSpeed = speed;
    else
        currSpeed = GifAnimationConsts::standardSpeed;
}

int GifAnimation::speed() const
{
    return currSpeed;
}

void GifAnimation::setRotation(const int &rotation)
{
    proxy->setRotation(rotation);
}

void GifAnimation::start()
{
    animation->setVisible(true);
    movie->start();
    connect(movie, SIGNAL(finished()), this, SLOT(stop()));
}

void GifAnimation::stop()
{
    movie->stop();
    animation->setVisible(false);
}






