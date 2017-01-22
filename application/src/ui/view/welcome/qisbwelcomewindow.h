#ifndef QISBWELCOMEWINDOW_H
#define QISBWELCOMEWINDOW_H

#include "qisbwindow.h"

class QisbWelcomeWindow : public QisbWindow
{
  Q_OBJECT

public:
  QisbWelcomeWindow(QWidget* parent = 0);
  virtual ~QisbWelcomeWindow();

public slots:
  virtual void insert(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings);
  virtual void remove(const QString &uid, const QMap<QString, QString> &settings);
  virtual void change(const QString &uid, const QMap<QString, QString> &properties, const QMap<QString, QString> &previous, const QMap<QString, QString> &settings);
  virtual void select(const QString &uid, const QMap<QString, QString> &settings);
};

#endif // QISBWELCOMEWINDOW_H
