#ifndef SHOOTANIMATION_H
#define SHOOTANIMATION_H

#include <QObject>

#include <QtGui/QLabel>
#include <QtGui/QMovie>
#include <QtGui/QGraphicsProxyWidget>
#include <QtGui/QGraphicsScene>

class ShootAnimation : public QObject
{
    Q_OBJECT
public:
    ShootAnimation();
    ~ShootAnimation();

    bool isSceneSet();

    void setPos(qreal x, qreal y);
    void setScene(QGraphicsScene *pScene);
    void start();

public slots:
    void stop();

private:
    qreal const scale;

    bool isSceneAlreadySet;

    QLabel *animation;
    QMovie *movie;
    QGraphicsProxyWidget *proxy;
};

#endif // SHOOTANIMATION_H
