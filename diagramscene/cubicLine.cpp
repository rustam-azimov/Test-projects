#include "cubicLine.h"

#include <qmath.h>

const qreal Pi = 3.14;
const int strokerWidth = 10;
const int lineWidth = 3;
const QColor selectedLineColor(0,175,0);

CubicLine::CubicLine(QGraphicsScene *scene, DiagramItem *startItem,
                     DiagramItem *endItem)
    : myStartItem(startItem),
      myEndItem(endItem),
      myColor(Qt::black),
      hasTail(false)
{
    for (int i = 0; i < numOfPoints; i++)
    {
        controlPoints[i] = new MovablePointItem;
        controlPoints[i]->setZValue(1100);
    }

    setInitialPoints();

    for (int i = 0; i < numOfPoints; i++)
         scene->addItem(controlPoints[i]);

    for (int i = 0; i < numOfPoints; i++)
        QObject::connect(controlPoints[i], SIGNAL(changePos()), scene, SLOT(update()));

    setFlag(QGraphicsItem::ItemIsSelectable);

    this->setAcceptHoverEvents(true);

    arrowHead.clear();
    arrowTail.clear();
}

QRectF CubicLine::boundingRect() const
{
    QPolygonF boundingPolygon;
    for (int i = 0; i < numOfPoints; i++)
        boundingPolygon << controlPoints[i]->pos();

    return boundingPolygon.boundingRect();
}

QPainterPath CubicLine::shape() const
{
    QPainterPath myPath(controlPoints[0]->pos());
    myPath.cubicTo(controlPoints[1]->pos(), controlPoints[2]->pos(),
                   controlPoints[3]->pos());

    myPath.addPolygon(arrowHead);
    myPath.addPolygon(arrowTail);

    QPainterPathStroker stroker;
    stroker.setWidth(strokerWidth);
    return stroker.createStroke(myPath);
}

void CubicLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget)
{
    setPointsVisible();

    stayOnItem(controlPoints[0], myStartItem, localStartPoint);
    stayOnItem(controlPoints[3], myEndItem, localEndPoint);

    if (isSomethingSelected())
    {
        painter->drawLine(controlPoints[0]->pos(), controlPoints[1]->pos());
        painter->drawLine(controlPoints[3]->pos(), controlPoints[2]->pos());
    }

    QPen pen;
    pen.setWidth(lineWidth);
    if (this->isSelected())
        pen.setColor(selectedLineColor);
    else
        pen.setColor(myColor);

    painter->setPen(pen);
    painter->setBrush(pen.color());

    setArrowTo(controlPoints[2]->pos(), controlPoints[3]->pos(), arrowHead);
    painter->drawPolygon(arrowHead);

    if (hasTail)
    {
        setArrowTo(controlPoints[1]->pos(), controlPoints[0]->pos(), arrowTail);
        painter->drawPolygon(arrowTail);
    }

    painter->setBrush(Qt::NoBrush);

    QPainterPath myPath(controlPoints[0]->pos());
    myPath.cubicTo(controlPoints[1]->pos(), controlPoints[2]->pos(),
                   controlPoints[3]->pos());

    painter->drawPath(myPath);
}

void CubicLine::updatePosition()
{
    controlPoints[0]->setPos(mapFromItem(myStartItem, localStartPoint));
    controlPoints[3]->setPos(mapFromItem(myEndItem, localEndPoint));
}

void CubicLine::clearPoints()
{
    for (int i = 0; i < numOfPoints; i++)
        delete controlPoints[i];
}

void CubicLine::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(QCursor(Qt::PointingHandCursor));
}

void CubicLine::setPointsVisible()
{
    bool isSelected = this->isSomethingSelected();

    for (int i = 0; i < numOfPoints; i++)
        controlPoints[i]->setVisible(isSelected);
}

bool CubicLine::isSomethingSelected()
{
    bool isPointSelected = false;

    for (int i = 0; i < numOfPoints; i++)
        isPointSelected = isPointSelected || controlPoints[i]->isSelected();

    return (this->isSelected() || isPointSelected);
}

void CubicLine::setInitialPoints()
{
    QPointF startPoint = intersectionPoint(myStartItem, myStartItem->pos(), myEndItem->pos());
    localStartPoint = mapToItem(myStartItem, startPoint);

    QPointF endPoint = intersectionPoint(myEndItem, myStartItem->pos(), myEndItem->pos());
    localEndPoint = mapToItem(myEndItem, endPoint);

    controlPoints[0]->setPos(startPoint);
    controlPoints[1]->setPos(2 * (startPoint / 3) + (endPoint / 3));
    controlPoints[2]->setPos((startPoint / 3) + 2 * (endPoint / 3));
    controlPoints[3]->setPos(endPoint);
}

QPointF CubicLine::intersectionPoint(DiagramItem *myItem, QPointF startPoint, QPointF endPoint)
{
    QLineF centerLine(startPoint, endPoint);

    QPolygonF myPolygon = myItem->polygon();
    QPointF p1 = myPolygon.first() + myItem->pos();
    QPointF p2;
    QPointF intersectPoint;
    QLineF polyLine;

    for (int i = 1; i < myPolygon.count(); ++i)
    {
        p2 = myPolygon.at(i) + myItem->pos();
        polyLine = QLineF(p1, p2);
        QLineF::IntersectType intersectType =
        polyLine.intersect(centerLine, &intersectPoint);
    if (intersectType == QLineF::BoundedIntersection)
        break;
        p1 = p2;
    }

    return intersectPoint;
}

void CubicLine::setArrowTo(QPointF start, QPointF end, QPolygonF &arrow)
{
    qreal posX = start.rx() - end.rx();
    qreal posY = start.ry() - end.ry();

    qreal angle = Pi - qAtan2(posX, posY);

    QPointF arrowP1 = (end + QPointF(sin(angle + Pi / 6) * 12,
                                     -cos(angle + Pi / 6) * 12));
    QPointF arrowP2 = (end - QPointF(sin(angle + Pi - Pi / 6) * 12,
                                     -cos(angle + Pi - Pi / 6) * 12));

    arrow.clear();
    arrow << end << arrowP1 << arrowP2;
}

void CubicLine::stayOnItem(MovablePointItem *controlPoint,
                               DiagramItem *item, QPointF &localPoint)
{
    if (!controlPoint->isSelected())
        return;

    if (controlPoint->collidesWithItem(item))
    {
        localPoint = mapToItem(item, controlPoint->pos());
        return;
    }

    localPoint = mapToItem(item, intersectionPoint(item,
                              item->pos(), controlPoint->pos()));
    controlPoint->setPos(mapFromItem(item, localPoint));
}

