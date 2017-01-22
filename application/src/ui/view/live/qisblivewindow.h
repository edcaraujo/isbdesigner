#ifndef QISBLIVEWINDOW_H
#define QISBLIVEWINDOW_H

#include "qisbwindow.h"

class QisbLiveWindow : public QisbWindow
{
  Q_OBJECT

public:
  QisbLiveWindow(QWidget* parent = 0);
  virtual ~QisbLiveWindow();

public slots:
  virtual void insert(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings);
  virtual void remove(const QString &uid, const QMap<QString, QString> &settings);
  virtual void change(const QString &uid, const QMap<QString, QString> &properties, const QMap<QString, QString> &previous, const QMap<QString, QString> &settings);
  virtual void select(const QString &uid, const QMap<QString, QString> &settings);
};

#endif // QISBLIVEWINDOW_H
