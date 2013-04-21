#include "field.h"
#include <QGraphicsScene>
#include <QPainter>
#include "QGraphicsRectItem"

Field::Field()
{
    colorArray = new bool*[gridWidth];
    for (int i = 0; i < gridWidth; i++)
        colorArray[i] = new bool[gridHeight];
    for (int i = 0; i < gridWidth; i++)
        for (int j = 0; j < gridHeight; j++)
            colorArray[i][j] = true;
    ant = new LangtonAnt(gridWidth / 2, gridHeight / 2);
}

Field::~Field()
{
    for (int i = 0; i < gridWidth; i++)
        delete[] colorArray[i];
    delete[] colorArray;
    delete ant;
}

QRectF Field::boundingRect() const
{
    return QRectF(0, 0, sceneWidth, sceneHeight);
}

void Field::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(sceneWidth / 2, sceneHeight / 2, gridSize, gridSize);
}


void Field::advance(int step)
{
    if (!step)
        return;

    int originX = ant->currentX;
    int originY = ant->currentY;

    ant->doStep(colorArray[ant->currentX][ant->currentY]);

    if(colorArray[originX][originY])
    {
        colorArray[originX][originY] = false;
        this->scene()->addRect(originX * gridSize, originY * gridSize,
                               gridSize, gridSize)->setBrush(Qt::black);
    } else
    {
        colorArray[originX][originY] = true;
        this->scene()->addRect(originX * gridSize, originY * gridSize,
                               gridSize, gridSize)->setBrush(Qt::white);
    }

    this->scene()->addRect(ant->currentX * gridSize, ant->currentY * gridSize,
                           gridSize, gridSize)->setBrush(Qt::red);
}
