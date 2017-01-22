#include "qisbnarrativewindow.h"

QisbNarrativeWindow::QisbNarrativeWindow(QWidget* parent)
  : QisbWindow(parent)
{
  setId("NAR");
  setTitle("Narrative View");

  createMenus();
  createActions();
  createToolbar();
  createWidgets();
  createConnections();
}

QisbNarrativeWindow::~QisbNarrativeWindow()
{

}

void QisbNarrativeWindow::createMenus()
{
  // TODO
}

void QisbNarrativeWindow::createActions()
{
  // TODO
}

void QisbNarrativeWindow::createToolbar()
{
  // TODO
}

void QisbNarrativeWindow::createWidgets()
{
  _menu = new QisbNarrativeMenu(this);
  _menu->adjust();

  _scene = new QisbNarrativeScene(this);
  _scene->setSize(1000, 1000);
  _scene->setMenu(_menu);

  _view = new QisbNarrativeView(this);
  _view->setScene(_scene);

  setCentralWidget(_view);
}

void QisbNarrativeWindow::createConnections()
{
  // TODO
}

void QisbNarrativeWindow::insert(const QString &uid, const QString &parent, const QMap<QString,QString> &properties, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(parent);
  Q_UNUSED(properties);
  Q_UNUSED(settings);

  // TODO
}

void QisbNarrativeWindow::remove(const QString &uid, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(settings);

  // TODO
}

void QisbNarrativeWindow::change(const QString &uid, const QMap<QString,QString> &properties, const QMap<QString, QString> &previous, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(properties);
  Q_UNUSED(previous);
  Q_UNUSED(settings);

  // TODO
}

void QisbNarrativeWindow::select(const QString &uid, const QMap<QString,QString> &settings)
{
  Q_UNUSED(uid);
  Q_UNUSED(settings);

  // TODO
}
