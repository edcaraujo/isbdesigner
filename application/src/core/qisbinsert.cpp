#include "qisbinsert.h"

QisbInsert::QisbInsert(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings)
  : QisbCommand()
{
  _uid = uid;
  _parent = parent;
  _properties = properties; _settings = settings;
}

QisbInsert::~QisbInsert()
{

}

void QisbInsert::undo()
{
  _settings[ISB_SETTING_UNDO] = ISB_VALUE_FALSE;

  emit removed(_uid, _settings);
}

void QisbInsert::redo()
{
  _settings[ISB_SETTING_UNDO] = ISB_VALUE_FALSE;

  emit inserted(_uid, _parent, _properties, _settings);
}
