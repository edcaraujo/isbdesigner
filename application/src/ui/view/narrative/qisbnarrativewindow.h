#ifndef QISBNARRATIVEWINDOW_H
#define QISBNARRATIVEWINDOW_H

#include "qisbwindow.h"
#include "qisbnarrativeview.h"
#include "qisbnarrativescene.h"
#include "qisbnarrativemenu.h"

class QisbNarrativeWindow : public QisbWindow
{
  Q_OBJECT

public:
  QisbNarrativeWindow(QWidget* parent = 0);
  virtual ~QisbNarrativeWindow();

public slots:
  virtual void insert(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings);
  virtual void remove(const QString &uid, const QMap<QString, QString> &settings);
  virtual void change(const QString &uid, const QMap<QString, QString> &properties, const QMap<QString, QString> &previous, const QMap<QString, QString> &settings);
  virtual void select(const QString &uid, const QMap<QString, QString> &settings);

private:
  virtual void createMenus();
  virtual void createActions();
  virtual void createToolbar();
  virtual void createWidgets();
  virtual void createConnections();

  QisbNarrativeView* _view;
  QisbNarrativeScene* _scene;
  QisbNarrativeMenu* _menu;
};

#endif // QISBNARRATIVEWINDOW_H
