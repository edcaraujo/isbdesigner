#ifndef QISBVIEW_H
#define QISBVIEW_H

#include <QGraphicsView>

class QisbView : public QGraphicsView
{
public:
  QisbView(QWidget* parent = 0);
  virtual ~QisbView();
};

#endif // QISBVIEW_H
