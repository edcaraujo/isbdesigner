#include "qisbnarrativescene.h"

QisbNarrativeScene::QisbNarrativeScene(QObject* parent)
  : QisbScene(parent)
{
  setMenu(NULL);
}

QisbNarrativeScene::~QisbNarrativeScene()
{

}

QisbNarrativeMenu* QisbNarrativeScene::getMenu() const
{
  return _menu;
}

void QisbNarrativeScene::setMenu(QisbNarrativeMenu* menu)
{
  _menu = menu;
}

void QisbNarrativeScene::contextMenuEvent(QGraphicsSceneContextMenuEvent* event)
{
  QisbScene::contextMenuEvent(event);



  if (_menu != NULL)
  {
    if (!event->isAccepted()) {
      _menu->setTop(event->scenePos().y());
      _menu->setLeft(event->scenePos().x());
      _menu->adjust();

      _menu->exec(event->screenPos());

      event->accept();
    }
  }
}
