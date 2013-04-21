#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsItem>

#include "langtonAnt.h"

/**
 * @file field.h
 *
 * @section DESCRIPTION
 *
 * This file contains a class Field.
 */

/// @class Field
class Field : public QGraphicsItem
{
public:
    /// Init all elements of the colorArray array equal to true.
    /// And sets ant in the center of scene.
    Field();
    ~Field();
    /// The Field area is equal to scene area.
    QRectF boundingRect() const;
    /// Draw ant like a red rectangle.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
protected:
    /// This method caused depending on timer, and draw red rectangle in new
    /// position of the ant, and draw black/white rectangle in old.
    void advance(int step);
private:
    LangtonAnt* ant;
    /// This array assigns to each cell in our grid the bool value
    /// (true if it colored white, and false else).
    bool** colorArray;
};

#endif // FIELD_H
