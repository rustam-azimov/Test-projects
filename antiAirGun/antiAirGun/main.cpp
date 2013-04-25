#include <QtGui/QApplication>
#include <QTimer>

#include "gameWidget.h"
#include "airGun.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameWidget view;
    view.setFixedSize(sceneWidth + 2, sceneHeight + 2);
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), view.scene, SLOT(advance()));
    timer.start(40);

    return a.exec();
}
