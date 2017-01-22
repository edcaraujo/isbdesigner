#include "qisbauthorwindow.h"

QisbAuthorWindow::QisbAuthorWindow(QWidget* parent)
  : QisbWindow(parent)
{
  setId("AUT");
  setTitle("Authoring View");
}

QisbAuthorWindow::~QisbAuthorWindow()
{

}

void QisbAuthorWindow::insert(const QString &uid, const QString &parent, const QMap<QString,QString> &properties, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(parent);
  Q_UNUSED(properties);
  Q_UNUSED(settings);

  // TODO
}

void QisbAuthorWindow::remove(const QString &uid, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(settings);

  // TODO
}

void QisbAuthorWindow::change(const QString &uid, const QMap<QString,QString> &properties, const QMap<QString, QString> &previous, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(properties);
  Q_UNUSED(previous);
  Q_UNUSED(settings);

  // TODO
}

void QisbAuthorWindow::select(const QString &uid, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(settings);

  // TODO
}

