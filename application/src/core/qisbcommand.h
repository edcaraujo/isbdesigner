#ifndef QISBCOMMAND_H
#define QISBCOMMAND_H

#include <QUndoCommand>
#include <QObject>
#include <QMap>
#include <QString>

#include "qisb.h"

class QisbCommand : public QObject, public QUndoCommand
{
  Q_OBJECT

public:
  QisbCommand(QisbCommand* parent = 0);
  virtual ~QisbCommand();

  virtual void undo() = 0;
  virtual void redo() = 0;

signals:
  void inserted(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings);
  void removed(const QString &uid, const QMap<QString, QString> &settings);
  void changed(const QString &uid, const QMap<QString, QString> &properties, const QMap<QString, QString> &previous, const QMap<QString, QString> &settings);
  void selected(const QString &uid, const QMap<QString, QString> &settings);
};

#endif // QISBCOMMAND_H
