#ifndef CUBICLINE_H
#define CUBICLINE_H

#include <QObject>
#include <QtGui>
#include "movablePointItem.h"
#include "diagramitem.h"
#include "diagramscene.h"

const int numOfPoints = 4;

class CubicLine : public QGraphicsItem
{
public:
    enum { Type = UserType + 4 };

    CubicLine(QGraphicsScene *scene,DiagramItem *startItem, DiagramItem *endItem);

    int type() const
        { return Type; }

    /// Sets bounding rect to bounding rect of shape.
    QRectF boundingRect() const;
    QPainterPath shape() const;

    /// Paint the bezier curve using QPainterPath::cubicTo. Leaves the curve start and end points inside the DiagramItem.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

    void setColor(const QColor &color)
        { myColor = color; }

    DiagramItem *startItem() const
        { return myStartItem; }
    DiagramItem *endItem() const
        { return myEndItem; }

    void updatePosition();

    void setArrowTail() { hasTail = true; }

    void clearPoints();

protected:
    /// Changes the cursor than hovering.
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);

    /// Makes a points visible, if a point or curve is selected; otherwise makes a points invisible.
    void setPointsVisible();

    /// Returns true, if a point or curve is selected; otherwise returns false.
    bool isSomethingSelected();

    void setInitialPoints();

    /// Returns the intersection point of edge of the DiagramItem and line passing through the startPoint and endPoint.
    QPointF intersectionPoint(DiagramItem *myItem,
                                  QPointF startPoint, QPointF endPoint);

    /// Returns the polygon of arrow head to end point.
    void setArrowTo(QPointF start, QPointF end, QPolygonF &arrow);

    /// Leaves the curve start and end points inside the DiagramItem.
    void stayOnItem(MovablePointItem *controlPoint, DiagramItem *item, QPointF &localPoint);

private:
    DiagramItem *myStartItem;
    DiagramItem *myEndItem;
    QColor myColor;

    bool hasTail;

    /// Coordinates of start point in local coordinates of start diagram item.
    QPointF localStartPoint;
    /// Coordinates of end point in local coordinates of end item.
    QPointF localEndPoint;

    /// Array contained control points. [0] - start point; [3] - last point; [1] and [2] - midpoints.
    MovablePointItem *controlPoints[numOfPoints];

    QPolygonF arrowHead;
    QPolygonF arrowTail;
};

#endif // CUBICLINE_H
