﻿#include <QPen>
#include "labpolygon.h"
#include "labline.h"

LabLine::LabLine(
    LabPolygon* _annItem,
	int _index,
	QColor _color
)
{
    // 初始化
    annItem = _annItem;
    index = _index;
    color = _color;
    // 设置
    setPen(QPen(color, minWidth));
    setZValue(11);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setAcceptHoverEvents(true);
    setBoundingRegionGranularity(0.5);
    updateWidth();
}

LabLine::~LabLine()
{

}

void LabLine::setColor(QColor c)
{
    setPen(QPen(color, minWidth));
    color = c;
}

void LabLine::updateWidth()
{
    setPen(QPen(color, minWidth));
}

QPolygonF LabLine::boundingPolygon()
{
    double w = minWidth * 1.5;
    w = w < 2 ? w : 2;
    QPointF start = line().p1();
    QPointF end = line().p2();
    QPointF dir = start - end;
    double dx, dy;
    dx = -dir.y();
    dy = dir.x();
    double norm = sqrt(dx * dx + dy * dy);
    dx /= (norm + 1e-16);
    dy /= (norm + 1e-16);
    QPointF point(dx * w, dy * w);
    QList<QPointF> pointList = QList<QPointF>() << \
        start - point << start + point << \
        end + point << end - point;
    QPolygonF poly = QPolygonF(pointList);
    return poly;
}
    
void LabLine::hoverEnterEvent(QGraphicsSceneHoverEvent* ev)
{
    boundingPolygon();
    annItem->lineHovering = true;
    setPen(QPen(color, minWidth * 1.4));
    QGraphicsLineItem::hoverEnterEvent(ev);
}

void LabLine::hoverLeaveEvent(QGraphicsSceneHoverEvent* ev)
{
    annItem->lineHovering = false;
    setPen(QPen(color, minWidth));
    QGraphicsLineItem::hoverLeaveEvent(ev);
}

void LabLine::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* ev)
{
    setPen(QPen(color, minWidth));
    annItem->addPointMiddle(index, ev->pos());
    QGraphicsLineItem::mouseDoubleClickEvent(ev);

}

QPainterPath LabLine::shape()
{
    QPainterPath path;
    path.addPolygon(boundingPolygon());
    return path;
}
