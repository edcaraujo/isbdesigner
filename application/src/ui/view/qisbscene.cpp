#include "qisbscene.h"

QisbScene::QisbScene(QObject* parent)
  : QGraphicsScene(parent)
{
  setSize(0, 0);
  setBackgroundBrush(QPixmap(":/images/background/view"));
}

QisbScene::~QisbScene()
{

}

qreal QisbScene::getWidth()
{
  return _width;
}

void QisbScene::setWidth(qreal width)
{
  _width = width;

  setSceneRect(0,0,width,_height);
}

qreal QisbScene::getHeight()
{
  return _height;
}

void QisbScene::setHeight(qreal height)
{
  _height = height;

  setSceneRect(0,0,_width,height);
}

void QisbScene::setSize(qreal width, qreal height)
{
  _width = width;
  _height = height;

  setSceneRect(0,0,width,height);
}
