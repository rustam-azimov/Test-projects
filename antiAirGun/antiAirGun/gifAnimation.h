#ifndef GIFANIMATION_H
#define GIFANIMATION_H

#include <QObject>

#include <QtWidgets/QLabel>
#include <QtGui/QMovie>
#include <QtWidgets/QGraphicsProxyWidget>
#include <QtWidgets/QGraphicsScene>

/**
 * @file gifAnimation.h
 *
 * Implementation of GifAnimation class.
 * Contained all to play gif-animation on scene.
 */

namespace GifAnimationConsts
{
    int const standardSpeed = 100;
    int const standardScale = 1;
}

/**
 * @class GifAnimation
 *
 * @brief
 * To play gif-animatiom on scene you should set a QLabel to the
 * QGraphicsProxyWidget and then set the label to use your gif as a QMovie.
 */
class GifAnimation : public QObject
{
    Q_OBJECT
public:
    /// Constructs a GifAnimation object. GifAnimation will use read image data from fileName.
    GifAnimation(const QString &fileName);

    /// Destructs the GifAnimation object.
    ~GifAnimation();

    /// Returns true if the scene is set; otherwise returns false.
    bool isSceneSet() const;

    /// Sets the position of the item to (x, y) position in scene coordinates.
    void setPos(qreal x, qreal y);

    /**
     * Sets the QGraphicsProxyWidget item on the scene.
     * You should set scale and speed before setting the scene; otherwise set as default.
     */
    void setOnScene(QGraphicsScene *pScene);

    /// Sets the animation scale to mScale. The default is 1.
    void setScale(const qreal &mScale);

    /// Sets  the animation speed to speed(in percent). The default is 100.
    void setSpeed(const int &speed);
    /// Returns the animation speed(in percent).
    int speed() const;

    /// Sets the animation rotation to rotation(in degrees). The default is 0.
    void setRotation(const int &rotation);

    /**
     * Starts the playback of animation and make the QGraphicsProxyWidget visible on scene.
     * You should always call start() after setOnScene(); otherwise can play incorrect.
     * Called stop() then the animation ends.
     */
    void start();

public slots:
    /// Stops the playback of animation and make the QGraphicsProxyWidget invisible on scene.
    void stop();

private:
    /// Scale of the gif-animation. Greater then 0. From 0 to 1 - decreasing, more than 1 - increasing.
    qreal scale;

    bool isSceneAlreadySet;

    /// Speed of the gif-animation(in percent).
    int currSpeed;

    QLabel *animation;
    QMovie *movie;
    QGraphicsProxyWidget *proxy;
};


#endif // GIFANIMATION_H
