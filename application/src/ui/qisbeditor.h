#ifndef QISBEDITOR_H
#define QISBEDITOR_H

#include <QStackedWidget>
#include <QUndoStack>
#include <QMap>
#include <QString>

#include <QDebug>

#include "qisbwindow.h"
#include "qisbentity.h"
#include "qisbinsert.h"
#include "qisbremove.h"
#include "qisbchange.h"

class QisbEditor : public QStackedWidget
{
  Q_OBJECT

public:
  QisbEditor(QWidget* parent = 0);
  virtual ~QisbEditor();

  void save(const QString &location);
  void load(const QString &location);
  void clean();

  void undo();
  void redo();

  QMap<QString, QisbWindow*> getWindows();
  void insertWindow(QisbWindow* window);
  void removeWindow(QisbWindow* window);
  void selectWindow(QisbWindow* window);

public slots:
  void insert(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings);
  void remove(const QString &uid, const QMap<QString, QString> &settings);
  void change(const QString &uid, const QMap<QString, QString> &properties, const QMap<QString, QString> &previous, const QMap<QString, QString> &settings);
  void select(const QString &uid, const QMap<QString, QString> &settings);

signals:
  void inserted(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings);
  void removed(const QString &uid, const QMap<QString, QString> &settings);
  void changed(const QString &uid, const QMap<QString, QString> &properties, const QMap<QString, QString> &previous, const QMap<QString, QString> &settings);
  void selected(const QString &uid, const QMap<QString, QString> &settings);

private:
  QMap<QString, QisbWindow*> _windows;
  QMap<QString, QisbEntity*> _entities;

  QUndoStack commands;
};

#endif // QISBEDITOR_H
