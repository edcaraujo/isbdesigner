#include "qisbsketchwindow.h"

QisbSketchWindow::QisbSketchWindow(QWidget* parent)
  : QisbWindow(parent)
{
  setId("SKE");
  setTitle("Sketch View");
}

QisbSketchWindow::~QisbSketchWindow()
{

}

void QisbSketchWindow::insert(const QString &uid, const QString &parent, const QMap<QString,QString> &properties, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(parent);
  Q_UNUSED(properties);
  Q_UNUSED(settings);

  // TODO
}

void QisbSketchWindow::remove(const QString &uid, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(settings);

  // TODO
}

void QisbSketchWindow::change(const QString &uid, const QMap<QString,QString> &properties, const QMap<QString, QString> &previous, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(properties);
  Q_UNUSED(previous);
  Q_UNUSED(settings);

  // TODO
}

void QisbSketchWindow::select(const QString &uid, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(settings);

  // TODO
}
