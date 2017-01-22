#ifndef QISBENTITY_H
#define QISBENTITY_H

#include <QMap>
#include <QString>
#include <QUuid>

#include "qisb.h"
#include "qisbutil.h"

class QisbEntity
{
public:
  QisbEntity(QisbEntity* parent = 0);
  virtual ~QisbEntity();

  QString getisbUid();
  void setisbUid(const QString &uid);

  QString getisbId();
  void setisbId(const QString &id);

  QString getisbProperty(const QString &name);
  void setisbProperty(const QString &name, const QString &value);

  QMap<QString,QString> getisbProperties();
  void setisbProperties(const QMap<QString,QString> &properties);

  QisbEntity* getisbParent();
  void setisbParent(QisbEntity* parent);

  virtual void adjust();

protected:
  QString _uid;
  QString _id;

  QisbEntity* _parent;
  QMap<QString,QString> _properties;
};

#endif // QISBENTITY_H
