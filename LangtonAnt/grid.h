#ifndef GRID_H
#define GRID_H

#include <QGraphicsItem>

/**
 * @file grid.h
 *
 * @section DESCRIPTION
 *
 * This file contains a definition of the fundamental constants, and class grid.
 */

/// @param sceneWidth - constant that sets the scene width in pixels.
/// MOST BE EVEN!!!
const int sceneWidth = 640;
/// @param sceneHeight - constant that sets the scene height in pixels.
/// MOST BE EVEN!!!
const int sceneHeight = 480;
/// @param gridSize - constant that specifies the size of the grid's cell in pixels.
/// MOST BE A DIVISOR OF sceneWidth AND DIVISOR OF sceneHeight!!!
const int gridSize = 20;
/// @param gridWidth - constant that sets the grid width in pixels.
const int gridWidth = sceneWidth / gridSize;
/// @param gridHeight - constant that sets the grid height in pixels.
const int gridHeight = sceneHeight / gridSize;

/// @class Grid
/// Object of this class - it is element of QGraphicsItem, which contains grid for the our scene.
class Grid : public QGraphicsItem
{
public:
    /// This method sets the size of the object of the class Grid equal to the size of the our scene.
    QRectF boundingRect() const;
    /// This method draws the grid, by the adding a rectangle with one side equal to 0.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
};

#endif // GRID_H
