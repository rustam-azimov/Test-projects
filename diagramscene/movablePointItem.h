#ifndef MYRECT_H
#define MYRECT_H

#include <QObject>
#include <QtGui/QGraphicsEllipseItem>
#include <QtGui/QGraphicsItem>
#include <QtGui/QBrush>
#include <QtGui/QCursor>

const qreal width = 10;
const qreal height = 10;

/**
 * @file movablePointItem.h
 *
 * Implementation of MovablePointItem class.
 * Creates movable, selectable circle item, which sends a signal when moved.
 */

class MovablePointItem : public QObject, public QGraphicsEllipseItem
{
Q_OBJECT
public:
    MovablePointItem()
    {
        setRect(-width / 2, -height / 2, width, height);
        setBrush(Qt::red);
        setFlags(QGraphicsItem::ItemIsMovable
               | QGraphicsItem::ItemIsSelectable
               | QGraphicsItem::ItemSendsGeometryChanges);

        setAcceptHoverEvents(true);
    }

protected:
    /// Emited the signal than item moved.
    QVariant itemChange(GraphicsItemChange change, const QVariant &value)
    {
        emit changePos();
        return value;
    }

    /// Changes the cursor than hovering.
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event)
    {
        this->setCursor(QCursor(Qt::PointingHandCursor));
    }

signals:
    void changePos();
};

#endif // MYRECT_H
