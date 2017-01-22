#ifndef QISBCHANGE_H
#define QISBCHANGE_H

#include "qisbcommand.h"

class QisbChange : public QisbCommand
{
public:
  QisbChange(const QString &uid, const QMap<QString, QString> &properties, const QMap<QString, QString> &previous, const QMap<QString, QString> &settings);
  virtual ~QisbChange();

  virtual void undo();
  virtual void redo();

private:
  QString _uid;
  QMap<QString, QString> _properties; QMap<QString, QString> _previous; QMap<QString, QString> _settings;
};

#endif // QISBCHANGE_H
