#include "qisbeditor.h"

QisbEditor::QisbEditor(QWidget* parent)
  : QStackedWidget(parent)
{

}

QisbEditor::~QisbEditor()
{

}

void QisbEditor::save(const QString &location)
{
  Q_UNUSED(location);

  // TODO
}

void QisbEditor::load(const QString &location)
{
  Q_UNUSED(location);

  // TODO
}

void QisbEditor::clean()
{
  // TODO
}

void QisbEditor::undo()
{
  if (_commands.canUndo())
  {
    QString code = _commands.undoText();

    while(code == _commands.undoText())
      _commands.undo();
  }
}

void QisbEditor::redo()
{
  if (_commands.canRedo())
  {
    QString code = _commands.redoText();

    while(code == _commands.redoText())
      _commands.redo();
  }
}

QMap<QString, QisbWindow*> QisbEditor::getWindows()
{
  return _windows;
}

void QisbEditor::insertWindow(QisbWindow* view)
{
  if (view != NULL){
    if (!_windows.contains(view->getId())){
      connect(view, SIGNAL(inserted(QString,QString,QMap<QString,QString>,QMap<QString,QString>)), SLOT(insert(QString,QString,QMap<QString,QString>,QMap<QString,QString>)));
      connect(view, SIGNAL(changed(QString,QMap<QString,QString>,QMap<QString,QString>,QMap<QString,QString>)),SLOT(change(QString,QMap<QString,QString>,QMap<QString,QString>,QMap<QString,QString>)));
      connect(view, SIGNAL(removed(QString,QMap<QString,QString>)), SLOT(remove(QString,QMap<QString,QString>)));
      connect(view, SIGNAL(selected(QString,QMap<QString,QString>)), SLOT(select(QString,QMap<QString,QString>)));

      _windows[view->getId()] = view; addWidget(view);
    }
  }
}

void QisbEditor::removeWindow(QisbWindow* view)
{
  if (view != NULL){
    if (_windows.contains(view->getId())){
      disconnect(view, SIGNAL(inserted(QString,QString,QMap<QString,QString>,QMap<QString,QString>)), this, SLOT(insert(QString,QString,QMap<QString,QString>,QMap<QString,QString>)));
      disconnect(view, SIGNAL(changed(QString,QMap<QString,QString>,QMap<QString,QString>,QMap<QString,QString>)), this, SLOT(change(QString,QMap<QString,QString>,QMap<QString,QString>,QMap<QString,QString>)));
      disconnect(view, SIGNAL(removed(QString,QMap<QString,QString>)), this, SLOT(remove(QString,QMap<QString,QString>)));
      disconnect(view, SIGNAL(selected(QString,QMap<QString,QString>)), this, SLOT(select(QString,QMap<QString,QString>)));

      _windows.remove(view->getId()); removeWidget(view);
    }
  }
}

void QisbEditor::selectWindow(QisbWindow* view)
{
  if (view != NULL){
    if (_windows.contains(view->getId())){
      setCurrentWidget(view);
    }
  }
}

void QisbEditor::insert(const QString &uid, const QString &parent, const QMap<QString,QString> &properties, const QMap<QString,QString> &settings)
{
  qDebug() << "[ISB]" << ":" << "Inserting entity" << QString(uid);

  if (!_entities.contains(uid))
  {
    if (settings[ISB_SETTING_UNDO] == ISB_VALUE_TRUE)
    {
      QisbInsert* command = new QisbInsert(uid, parent, properties, settings);
      command->setText(settings[ISB_SETTING_CODE]);

      connect(command, SIGNAL(inserted(QString,QString,QMap<QString,QString>,QMap<QString,QString>)), SLOT(insert(QString,QString,QMap<QString,QString>,QMap<QString,QString>)));
      connect(command, SIGNAL(removed(QString,QMap<QString,QString>)),SLOT(remove(QString,QMap<QString,QString>)));
      connect(command, SIGNAL(changed(QString,QMap<QString,QString>,QMap<QString,QString>,QMap<QString,QString>)), SLOT(change(QString,QMap<QString,QString>,QMap<QString,QString>,QMap<QString,QString>)));
      connect(command, SIGNAL(selected(QString,QMap<QString,QString>)),SLOT(select(QString,QMap<QString,QString>)));

      _commands.push(command); return;
    }

    QisbEntity* entity = new QisbEntity();
    entity->setisbUid(uid);
    entity->setisbProperties(properties);

    _entities[entity->getisbUid()] = entity;

    foreach(QisbWindow* view, _windows.values())
      view->insert(uid, parent, properties, settings);

    if (settings[ISB_SETTING_NOTIFY] == ISB_VALUE_TRUE)
    {
      emit inserted(uid, parent, properties, settings);
    }
  }
}

void QisbEditor::remove(const QString &uid, const QMap<QString,QString> &settings)
{
  qDebug() << "[ISB]" << ":" << "Removing entity" << QString(uid);

  if (_entities.contains(uid))
  {
    if (settings[ISB_SETTING_UNDO] == ISB_VALUE_TRUE)
    {
      QisbRemove* command = new QisbRemove(uid, _entities[uid]->getisbParent()->getisbUid(), _entities[uid]->getisbProperties(), settings);
      command->setText(settings[ISB_SETTING_CODE]);

      connect(command, SIGNAL(inserted(QString,QString,QMap<QString,QString>,QMap<QString,QString>)), SLOT(insert(QString,QString,QMap<QString,QString>,QMap<QString,QString>)));
      connect(command, SIGNAL(removed(QString,QMap<QString,QString>)),SLOT(remove(QString,QMap<QString,QString>)));
      connect(command, SIGNAL(changed(QString,QMap<QString,QString>,QMap<QString,QString>,QMap<QString,QString>)), SLOT(change(QString,QMap<QString,QString>,QMap<QString,QString>,QMap<QString,QString>)));
      connect(command, SIGNAL(selected(QString,QMap<QString,QString>)),SLOT(select(QString,QMap<QString,QString>)));

      _commands.push(command); return;
    }

    delete _entities[uid]; _entities.remove(uid);

    foreach(QisbWindow* view, _windows.values())
      view->remove(uid, settings);

    if (settings[ISB_SETTING_NOTIFY] == ISB_VALUE_TRUE)
    {
      emit removed(uid, settings);
    }
  }
}

void QisbEditor::change(const QString &uid, const QMap<QString,QString> &properties, const QMap<QString, QString> &previous, const QMap<QString,QString> &settings)
{
  qDebug() << "[ISB]" << ":" << "Changing entity" << QString(uid);

  if (_entities.contains(uid))
  {
    if (settings[ISB_SETTING_UNDO] == ISB_VALUE_TRUE)
    {
      QisbChange* command = new QisbChange(uid, properties, previous, settings);
      command->setText(settings[ISB_SETTING_CODE]);

      connect(command, SIGNAL(inserted(QString,QString,QMap<QString,QString>,QMap<QString,QString>)), SLOT(insert(QString,QString,QMap<QString,QString>,QMap<QString,QString>)));
      connect(command, SIGNAL(removed(QString,QMap<QString,QString>)),SLOT(remove(QString,QMap<QString,QString>)));
      connect(command, SIGNAL(changed(QString,QMap<QString,QString>,QMap<QString,QString>,QMap<QString,QString>)), SLOT(change(QString,QMap<QString,QString>,QMap<QString,QString>,QMap<QString,QString>)));
      connect(command, SIGNAL(selected(QString,QMap<QString,QString>)),SLOT(select(QString,QMap<QString,QString>)));

      _commands.push(command); return;
    }

    QisbEntity* entity = _entities[uid];
    entity->setisbProperties(properties);

    foreach(QisbWindow* view, _windows.values())
      view->change(uid, properties, previous, settings);

    if (settings[ISB_SETTING_NOTIFY] == ISB_VALUE_TRUE)
    {
      emit changed(uid, properties, previous, settings);
    }
  }
}

void QisbEditor::select(const QString &uid, const QMap<QString,QString> &settings)
{
  qDebug() << "[ISB]" << ":" << "Selecting entity" << QString(uid);

  foreach(QisbWindow* view, _windows.values())
    view->select(uid, settings);

  emit selected(uid, settings);
}
