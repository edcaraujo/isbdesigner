#ifndef QISBREMOVE_H
#define QISBREMOVE_H

#include "qisbcommand.h"

class QisbRemove : public QisbCommand
{
public:
  QisbRemove(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings);
  virtual ~QisbRemove();

  virtual void undo();
  virtual void redo();

private:
  QString _uid;
  QString _parent;
  QMap<QString, QString> _properties; QMap<QString, QString> _settings;
};

#endif // QISBREMOVE_H
