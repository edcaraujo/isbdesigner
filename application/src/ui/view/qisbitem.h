#ifndef QISBITEM_H
#define QISBITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QPainterPath>
#include <QStyleOptionGraphicsItem>

#include <QDebug>

#include "qisbentity.h"

class QisbItem : public QObject, public QGraphicsItem, public QisbEntity
{
public:
  QisbItem(QisbItem* parent = 0);
  virtual ~QisbItem();

  qreal getTop();
  void setTop(qreal top);

  qreal getLeft();
  void setLeft(qreal left);

  qreal getWidth();
  void setWidth(qreal width);

  qreal getHeight();
  void setHeight(qreal height);

  QisbItem* getisbParentItem();
  void setisbParentItem(QisbItem* parent);

protected:
  virtual void draw(QPainter* painter) = 0;
  virtual void delineate(QPainterPath* painter) const = 0;

  virtual QPainterPath shape() const;
  virtual QRectF boundingRect() const;
  virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
  qreal _top;
  qreal _left;
  qreal _width;
  qreal _height;

  QisbItem* _parent;
};

#endif // QISBITEM_H
