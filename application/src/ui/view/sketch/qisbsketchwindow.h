#ifndef QISBSKETCHWINDOW_H
#define QISBSKETCHWINDOW_H

#include "qisbwindow.h"

class QisbSketchWindow : public QisbWindow
{
  Q_OBJECT

public:
  QisbSketchWindow(QWidget* parent = 0);
  virtual ~QisbSketchWindow();

public slots:
  virtual void insert(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings);
  virtual void remove(const QString &uid, const QMap<QString, QString> &settings);
  virtual void change(const QString &uid, const QMap<QString, QString> &properties, const QMap<QString, QString> &previous, const QMap<QString, QString> &settings);
  virtual void select(const QString &uid, const QMap<QString, QString> &settings);
};

#endif // QISBSKETCHWINDOW_H
