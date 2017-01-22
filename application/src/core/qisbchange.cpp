#include "qisbchange.h"

QisbChange::QisbChange(const QString &uid, const QMap<QString, QString> &properties, const QMap<QString, QString> &previous, const QMap<QString, QString> &settings)
  : QisbCommand()
{
  _uid = uid;
  _properties = properties; _previous = previous; _settings = settings;
}

QisbChange::~QisbChange()
{

}

void QisbChange::undo()
{
  _settings[ISB_SETTING_UNDO] = ISB_VALUE_FALSE;

  emit changed(_uid, _previous, _properties, _settings);
}

void QisbChange::redo()
{
  _settings[ISB_SETTING_UNDO] = ISB_VALUE_FALSE;

  emit changed(_uid, _properties, _previous, _settings);
}
