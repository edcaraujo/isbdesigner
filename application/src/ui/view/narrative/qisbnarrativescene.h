#ifndef QISBNARRATIVESCENE_H
#define QISBNARRATIVESCENE_H

#include <QGraphicsSceneContextMenuEvent>

#include <QDebug>

#include "qisbscene.h"
#include "qisbnarrativemenu.h"

class QisbNarrativeScene : public QisbScene
{
public:
  QisbNarrativeScene(QObject* parent = 0);
  virtual ~QisbNarrativeScene();

  QisbNarrativeMenu* getMenu() const;
  void setMenu(QisbNarrativeMenu* menu);

protected:
  virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent* event);

private:
  QisbNarrativeMenu* _menu;
};

#endif // QISBNARRATIVESCENE_H
