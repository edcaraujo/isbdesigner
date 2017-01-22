#ifndef QISBSCENE_H
#define QISBSCENE_H

#include <QGraphicsScene>

class QisbScene : public QGraphicsScene
{
public:
  QisbScene(QObject* parent = 0);
  virtual ~QisbScene();

  qreal getWidth();
  void setWidth(qreal width);

  qreal getHeight();
  void setHeight(qreal height);

  void setSize(qreal width, qreal height);

private:
  qreal _width;
  qreal _height;
};

#endif // QISBSCENE_H
