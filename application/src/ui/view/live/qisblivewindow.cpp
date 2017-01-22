#include "qisblivewindow.h"

QisbLiveWindow::QisbLiveWindow(QWidget* parent)
    : QisbWindow(parent)
{
    setId("LIV");
    setTitle("Live View");
}

QisbLiveWindow::~QisbLiveWindow()
{

}

void QisbLiveWindow::insert(const QString &uid, const QString &parent, const QMap<QString,QString> &properties, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(parent);
  Q_UNUSED(properties);
  Q_UNUSED(settings);

  // TODO
}

void QisbLiveWindow::remove(const QString &uid, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(settings);

  // TODO
}

void QisbLiveWindow::change(const QString &uid, const QMap<QString,QString> &properties, const QMap<QString, QString> &previous, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(properties);
  Q_UNUSED(previous);
  Q_UNUSED(settings);

  // TODO
}

void QisbLiveWindow::select(const QString &uid, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(settings);

  // TODO
}

