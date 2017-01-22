#include "qisbsummarywindow.h"

QisbSummaryWindow::QisbSummaryWindow(QWidget* parent)
  : QisbWindow(parent)
{
  setId("SUM");
  setTitle("Summary View");
}

QisbSummaryWindow::~QisbSummaryWindow()
{

}

void QisbSummaryWindow::insert(const QString &uid, const QString &parent, const QMap<QString,QString> &properties, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(parent);
  Q_UNUSED(properties);
  Q_UNUSED(settings);

  // TODO
}

void QisbSummaryWindow::remove(const QString &uid, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(settings);

  // TODO
}

void QisbSummaryWindow::change(const QString &uid, const QMap<QString,QString> &properties, const QMap<QString, QString> &previous, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(properties);
  Q_UNUSED(previous);
  Q_UNUSED(settings);

  // TODO
}

void QisbSummaryWindow::select(const QString &uid, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(settings);

  // TODO
}

