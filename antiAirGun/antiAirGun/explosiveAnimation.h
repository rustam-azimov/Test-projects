#ifndef EXPLOSIVEANIMATION_H
#define EXPLOSIVEANIMATION_H

#include <QObject>

#include <QtGui/QLabel>
#include <QtGui/QMovie>
#include <QtGui/QGraphicsProxyWidget>
#include <QtGui/QGraphicsScene>

class ExplosiveAnimation : public QObject
{
    Q_OBJECT
public:
    ExplosiveAnimation();
    ~ExplosiveAnimation();

    void setPos(qreal x, qreal y);
    void setScene(QGraphicsScene *pScene);
    void start();

public slots:
    void stop();

private:
    qreal const scale;

    QLabel *animation;
    QMovie *movie;
    QGraphicsProxyWidget *proxy;
};

#endif // EXPLOSIVEANIMATION_H
