#include "qisbitem.h"

QisbItem::QisbItem(QisbItem* parent)
  : QObject(parent), QGraphicsItem(parent), QisbEntity(parent)
{
  setisbParentItem(parent);
}

QisbItem::~QisbItem()
{

}

QisbItem* QisbItem::getisbParentItem()
{
  return _parent;
}

void QisbItem::setisbParentItem(QisbItem* parent)
{
  _parent = parent;
}

qreal QisbItem::getTop()
{
  return _top;
}

void QisbItem::setTop(qreal top)
{
  _top = top;
  _properties[ISB_PROPERTY_ITEM_TOP] = QString::number(top);

  setY(top-ISB_DEFAULT_ITEM_PADDING);
}

qreal QisbItem::getLeft()
{
  return _left;
}

void QisbItem::setLeft(qreal left)
{
  _left = left;
  _properties[ISB_PROPERTY_ITEM_LEFT] = QString::number(left);

  setX(left-ISB_DEFAULT_ITEM_PADDING);
}

qreal QisbItem::getWidth()
{
  return _width;
}

void QisbItem::setWidth(qreal width)
{
  _width = width;
  _properties[ISB_PROPERTY_ITEM_WIDTH] = QString::number(width);
}

qreal QisbItem::getHeight()
{
  return _height;
}

void QisbItem::setHeight(qreal height)
{
  _height = height;
  _properties[ISB_PROPERTY_ITEM_HEIGHT] = QString::number(height);
}

QPainterPath QisbItem::shape() const
{
  QPainterPath painter;

  delineate(&painter);

  return painter;
}

QRectF QisbItem::boundingRect() const
{
  QRectF bounds;

  bounds.setX(0);
  bounds.setY(0);
  bounds.setWidth(_width);
  bounds.setHeight(_height);

  return bounds;
}

void QisbItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  Q_UNUSED(option);
  Q_UNUSED(widget);

  painter->setRenderHint(QPainter::Antialiasing,true);
  painter->setRenderHint(QPainter::TextAntialiasing,true);
  painter->setRenderHint(QPainter::SmoothPixmapTransform,true);

  draw(painter);
}
