#include "qisbentity.h"

QisbEntity::QisbEntity(QisbEntity* parent)
{
  setisbUid(QisbUtil::Uid());
  setisbParent(parent);
}

QisbEntity::~QisbEntity()
{
  // TODO
}

QString QisbEntity::getisbUid()
{
  return _uid;
}

void QisbEntity::setisbUid(const QString &uid)
{
  _uid = uid;
  _properties[ISB_PROPERTY_ENTITY_UID] = uid;
}

QString QisbEntity::getisbId()
{
  return _id;
}

void QisbEntity::setisbId(const QString &id)
{
  _id = id;
  _properties[ISB_PROPERTY_ENTITY_ID] = id;
}

QisbEntity* QisbEntity::getisbParent()
{
  return _parent;
}

void QisbEntity::setisbParent(QisbEntity* parent)
{
  _parent = parent;
}

QString QisbEntity::getisbProperty(const QString &name)
{
  return _properties.value(name);
}

void QisbEntity::setisbProperty(const QString &name, const QString &value)
{
  _properties[name] = value;

  adjust();
}

QMap<QString,QString> QisbEntity::getisbProperties()
{
  return _properties;
}

void QisbEntity::setisbProperties(const QMap<QString,QString> &properties)
{
  foreach (QString name, properties.keys())
    _properties[name] = properties.value(name);

  adjust();
}

void QisbEntity::adjust()
{
  setisbProperty(ISB_PROPERTY_ENTITY_UID, _properties[ISB_PROPERTY_ENTITY_UID]);
  setisbProperty(ISB_PROPERTY_ENTITY_ID, _properties[ISB_PROPERTY_ENTITY_ID]);
}
