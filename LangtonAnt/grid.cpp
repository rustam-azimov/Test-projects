#include "grid.h"
#include <QPainter>

QRectF Grid::boundingRect() const
{
    return QRectF(0, 0, sceneWidth, sceneHeight);
}

void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    for (int i = 0; i < gridWidth; i++)
    {
        painter->drawRect(i * gridSize, 0, 0, sceneHeight);
    }
    for (int i = 0; i < gridHeight; i++)
    {
        painter->drawRect(0, i * gridSize, sceneWidth, 0);
    }
}
