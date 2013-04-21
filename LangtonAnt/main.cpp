#include <QGraphicsView>
#include <QGraphicsScene>

#include <QtGui>

#include "field.h"

/**
 * @file main.cpp
 *
 * @section DESCRIPTION
 *
 * This is a program which shows the movement of Langton's Ant.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, sceneWidth, sceneHeight);

    Grid* grid = new Grid;
    scene.addItem(grid);

    Field* field = new Field;
    scene.addItem(field);

    QGraphicsView view(&scene);
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1);


    return a.exec();
}
