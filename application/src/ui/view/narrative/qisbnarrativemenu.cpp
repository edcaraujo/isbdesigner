#include "qisbnarrativemenu.h"

QisbNarrativeMenu::QisbNarrativeMenu(QWidget* parent)
  : QMenu(parent)
{
  createActions();
  createMenus();
  createConnections();
}

QisbNarrativeMenu::~QisbNarrativeMenu()
{

}

qreal QisbNarrativeMenu::getTop() const
{
  return _top;
}

void QisbNarrativeMenu::setTop(qreal top)
{
  _top = top;
}

qreal QisbNarrativeMenu::getLeft() const
{
  return _left;
}

void QisbNarrativeMenu::setLeft(qreal left)
{
  _left = left;
}

void QisbNarrativeMenu::adjust()
{

}

void QisbNarrativeMenu::createActions()
{
  // help action
  _helpAction = new QAction(this);
  _helpAction->setEnabled(true);
  _helpAction->setText(tr("Help..."));
  _helpAction->setShortcut(QKeySequence("F1"));
  _helpAction->setIcon(QIcon(":/images/icon/help"));

  // undo action
  _undoAction = new QAction(this);
  _undoAction->setEnabled(true);
  _undoAction->setText(tr("Undo"));
  _undoAction->setShortcut(QKeySequence("Ctrl+Z"));
  _undoAction->setIcon(QIcon(":/images/icon/undo"));

  // redo action
  _redoAction = new QAction(this);
  _redoAction->setEnabled(true);
  _redoAction->setText(tr("Redo"));
  _redoAction->setShortcut(QKeySequence("Ctrl+Shift+Z"));
  _redoAction->setIcon(QIcon(":/images/icon/redo"));

  // cut action
  _cutAction = new QAction(this);
  _cutAction->setEnabled(true);
  _cutAction->setText(tr("Cut"));
  _cutAction->setShortcut(QKeySequence("Ctrl+X"));
  _cutAction->setIcon(QIcon(":/images/icon/cut"));

  // copy action
  _copyAction = new QAction(this);
  _copyAction->setEnabled(true);
  _copyAction->setText(tr("Copy"));
  _copyAction->setShortcut(QKeySequence("Ctrl+C"));
  _copyAction->setIcon(QIcon(":/images/icon/copy"));

  // paste action
  _pasteAction = new QAction(this);
  _pasteAction->setEnabled(true);
  _pasteAction->setText(tr("Paste"));
  _pasteAction->setShortcut(QKeySequence("Ctrl+V"));
  _pasteAction->setIcon(QIcon(":/images/icon/paste"));

  // delete action
  _deleteAction = new QAction(this);
  _deleteAction->setEnabled(true);
  _deleteAction->setText(tr("Delete"));
  _deleteAction->setShortcut(QKeySequence("Del"));
  _deleteAction->setIcon(QIcon(":/images/icon/delete"));

  // snapshot action
  _snapshotAction = new QAction(this);
  _snapshotAction->setEnabled(true);
  _snapshotAction->setText(tr("Take a Snapshot..."));
  _snapshotAction->setIcon(QIcon(":/images/icon/snapshot"));

  // sequence action
  _sequenceAction = new QAction(this);
  _sequenceAction->setEnabled(true);
  _sequenceAction->setText(tr("Sequence"));
  _sequenceAction->setIcon(QIcon(":/images/icon/sequence"));

  // properties action
  _propertiesAction = new QAction(this);
  _propertiesAction->setEnabled(true);
  _propertiesAction->setText(tr("Properties..."));
  _propertiesAction->setIcon(QIcon(":/images/icon/properties"));
}

void QisbNarrativeMenu::createMenus()
{
  // insert menu
  _insertMenu = new QMenu();
  _insertMenu->setTitle(tr("Insert"));
  _insertMenu->setIcon(QIcon(":/images/icon/insert"));

  _insertMenu->addAction(_sequenceAction);

  addAction(_helpAction);
  addSeparator();
  addMenu(_insertMenu);
  addSeparator();
  addAction(_undoAction);
  addAction(_redoAction);
  addSeparator();
  addAction(_cutAction);
  addAction(_copyAction);
  addAction(_pasteAction);
  addSeparator();
  addAction(_deleteAction);
  addSeparator();
  addAction(_snapshotAction);
  addSeparator();
  addAction(_propertiesAction);
}

void QisbNarrativeMenu::createConnections()
{
  connect(_helpAction,SIGNAL(triggered()),SIGNAL(performedHelp()));
  connect(_undoAction,SIGNAL(triggered()),SIGNAL(performedUndo()));
  connect(_redoAction,SIGNAL(triggered()),SIGNAL(performedRedo()));
  connect(_cutAction,SIGNAL(triggered()),SIGNAL(performedCut()));
  connect(_copyAction,SIGNAL(triggered()),SIGNAL(performedCopy()));
  connect(_pasteAction,SIGNAL(triggered()),SIGNAL(performedPaste()));
  connect(_deleteAction,SIGNAL(triggered()),SIGNAL(performedDelete()));
  connect(_snapshotAction,SIGNAL(triggered()),SIGNAL(performedSnapshot()));
  connect(_sequenceAction,SIGNAL(triggered()),SLOT(performSequence());
  connect(_propertiesAction,SIGNAL(triggered()),SIGNAL(performedProperties()));
}

void QisbNarrativeMenu::switchHelp(bool state)
{
  _helpAction->setEnabled(state);
}

void QisbNarrativeMenu::switchUndo(bool state)
{
  _undoAction->setEnabled(state);
}

void QisbNarrativeMenu::switchRedo(bool state)
{
  _redoAction->setEnabled(state);
}

void QisbNarrativeMenu::switchCut(bool state)
{
  _cutAction->setEnabled(state);
}

void QisbNarrativeMenu::switchCopy(bool state)
{
  _copyAction->setEnabled(state);
}

void QisbNarrativeMenu::switchPaste(bool state)
{
  _pasteAction->setEnabled(state);
}

void QisbNarrativeMenu::switchDelete(bool state)
{
  _deleteAction->setEnabled(state);
}

void QisbNarrativeMenu::switchSnapshot(bool state)
{
  _snapshotAction->setEnabled(state);
}

void QisbNarrativeMenu::switchSequence(bool state)
{
  _sequenceAction->setEnabled(state);
}

void QisbNarrativeMenu::switchProperties(bool state)
{
  _propertiesAction->setEnabled(state);
}

void QisbNarrativeMenu::performSequence()
{
  // TODO
}
