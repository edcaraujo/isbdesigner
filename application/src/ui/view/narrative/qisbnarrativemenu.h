#ifndef QISBNARRATIVEMENU_H
#define QISBNARRATIVEMENU_H

#include <QMenu>

#include "qisb.h"

class QisbNarrativeMenu : public QMenu
{
  Q_OBJECT

public:
  QisbNarrativeMenu(QWidget* parent = 0);
  virtual ~QisbNarrativeMenu();

  qreal getTop() const;
  void setTop(qreal top);

  qreal getLeft() const;
  void setLeft(qreal left);

  void adjust();

public slots:
  void switchHelp(bool state);
  void switchUndo(bool state);
  void switchRedo(bool state);
  void switchCut(bool state);
  void switchCopy(bool state);
  void switchPaste(bool state);
  void switchDelete(bool state);
  void switchSnapshot(bool state);
  void switchSequence(bool state);
  void switchProperties(bool state);

signals:
  void performedHelp();
  void performedUndo();
  void performedRedo();
  void performedCut();
  void performedCopy();
  void performedPaste();
  void performedDelete();
  void performedSnapshot();
  void performedSequence();
  void performedProperties();

  void performedInsert(QisbType type, const QMap<QString, QString> &properties);

private:
  void createActions();
  void createMenus();
  void createConnections();

private slots:
  void performSequence();

private:
  QMenu* _insertMenu;

  QAction* _helpAction;
  QAction* _undoAction;
  QAction* _redoAction;
  QAction* _cutAction;
  QAction* _copyAction;
  QAction* _pasteAction;
  QAction* _deleteAction;
  QAction* _snapshotAction;
  QAction* _sequenceAction;
  QAction* _propertiesAction;

  qreal _top;
  qreal _left;
};

#endif // QISBNARRATIVEMENU_H
