#ifndef QISBINSERT_H
#define QISBINSERT_H

#include "qisbcommand.h"

class QisbInsert : public QisbCommand
{
public:
  QisbInsert(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings);
  virtual ~QisbInsert();

  virtual void undo();
  virtual void redo();

private:
  QString _uid;
  QString _parent;
  QMap<QString, QString> _properties; QMap<QString, QString> _settings;
};

#endif // QISBINSERT_H
