#include <QtGui/QApplication>
#include <QTimer>

#include "gameWidget.h"
#include "airGun.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameWidget view;
    view.setFixedSize(770, 382);
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), view.scene, SLOT(advance()));
    timer.start(40);

    return a.exec();
}
