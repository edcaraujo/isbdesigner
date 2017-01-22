#include "qisbmainwindow.h"

QisbMainWindow::QisbMainWindow(QWidget* parent)
  : QMainWindow(parent)
{
  createActions();
  createMenus();
  createToolbar();
  createWidgets();
  createConnections();
}

QisbMainWindow::~QisbMainWindow()
{

}

void QisbMainWindow::createActions()
{
  // new action
  _newAction = new QAction(this);
  _newAction->setEnabled(true);
  _newAction->setText(tr("New"));
  _newAction->setIcon(QIcon(":/images/icon/new"));
  _newAction->setShortcut(QKeySequence("Ctrl+N"));


  // open action
  _openAction = new QAction(this);
  _openAction->setEnabled(true);
  _openAction->setText(tr("Open..."));
  _openAction->setIcon(QIcon(":/images/icon/open"));
  _openAction->setShortcut(QKeySequence("Ctrl+O"));

  // save action
  _saveAction = new QAction(this);
  _saveAction->setEnabled(true);
  _saveAction->setText(tr("Save"));
  _saveAction->setIcon(QIcon(":/images/icon/save"));
  _saveAction->setShortcut(QKeySequence("Ctrl+S"));

  // saveas action
  _saveAsAction = new QAction(this);
  _saveAsAction->setEnabled(true);
  _saveAsAction->setText(tr("Save As..."));
  _saveAsAction->setIcon(QIcon(":/images/icon/saveas"));
  _saveAsAction->setShortcut(QKeySequence("Shift+Ctrl+S"));

  // close action
  _closeAction = new QAction(this);
  _closeAction->setEnabled(true);
  _closeAction->setText(tr("Close"));
  _closeAction->setIcon(QIcon(":/images/icon/close"));
  _closeAction->setShortcut(QKeySequence("Ctrl+W"));

  // quit action
  _quitAction = new QAction(this);
  _quitAction->setEnabled(true);
  _quitAction->setText(tr("Quit"));
  _quitAction->setIcon(QIcon(":/images/icon/quit"));
  _quitAction->setShortcut(QKeySequence("Ctrl+Q"));

  // import action
  _importAction = new QAction(this);
  _importAction->setEnabled(true);
  _importAction->setText(tr("Import..."));
  _importAction->setIcon(QIcon(":/images/icon/import"));
  _importAction->setShortcut(QKeySequence("Ctrl+R"));

  // export action
  _exportAction = new QAction(this);
  _exportAction->setEnabled(true);
  _exportAction->setText(tr("Export..."));
  _exportAction->setIcon(QIcon(":/images/icon/export"));
  _exportAction->setShortcut(QKeySequence("Ctrl+Shift+R"));

  // undo action
  _undoAction = new QAction(this);
  _undoAction->setEnabled(true);
  _undoAction->setText(tr("Undo"));
  _undoAction->setIcon(QIcon(":/images/icon/undo"));
  _undoAction->setShortcut(QKeySequence("Ctrl+Z"));

  // redo action
  _redoAction = new QAction(this);
  _redoAction->setEnabled(true);
  _redoAction->setText(tr("Redo"));
  _redoAction->setIcon(QIcon(":/images/icon/redo"));
  _redoAction->setShortcut(QKeySequence("Ctrl+Shift+Z"));

  // cut action
  _cutAction = new QAction(this);
  _cutAction->setEnabled(true);
  _cutAction->setText(tr("Cut"));
  _cutAction->setIcon(QIcon(":/images/icon/cut"));
  _cutAction->setShortcut(QKeySequence("Ctrl+X"));

  // copy action
  _copyAction = new QAction(this);
  _copyAction->setEnabled(true);
  _copyAction->setText(tr("Copy"));
  _copyAction->setIcon(QIcon(":/images/icon/copy"));
  _copyAction->setShortcut(QKeySequence("Ctrl+C"));

  // paste action
  _pasteAction = new QAction(this);
  _pasteAction->setEnabled(true);
  _pasteAction->setText(tr("Paste"));
  _pasteAction->setIcon(QIcon(":/images/icon/paste"));
  _pasteAction->setShortcut(QKeySequence("Ctrl+V"));

  // sketch action
  _sketchAction = new QAction(this);
  _sketchAction->setEnabled(true);
  _sketchAction->setCheckable(true);
  _sketchAction->setChecked(true);
  _sketchAction->setText(tr("Sketch"));
  _sketchAction->setIcon(QIcon(":/images/icon/sketch"));
  _sketchAction->setToolTip(tr("Switch to Sketching View"));
  _sketchAction->setShortcut(QKeySequence("Ctrl+1"));

  // author action
  _authorAction = new QAction(this);
  _authorAction->setEnabled(true);
  _authorAction->setCheckable(true);
  _authorAction->setChecked(false);
  _authorAction->setText(tr("Author"));
  _authorAction->setIcon(QIcon(":/images/icon/author"));
  _authorAction->setToolTip(tr("Switch to Authoring View"));
  _authorAction->setShortcut(QKeySequence("Ctrl+2"));

  // narrative action
  _narrativeAction = new QAction(this);
  _narrativeAction->setEnabled(true);
  _narrativeAction->setCheckable(true);
  _narrativeAction->setChecked(false);
  _narrativeAction->setText(tr("Narrative"));
  _narrativeAction->setIcon(QIcon(":/images/icon/narrative"));
  _narrativeAction->setToolTip(tr("Switch to Narrative View"));
  _narrativeAction->setShortcut(QKeySequence("Ctrl+3"));

  // preferences action
  _preferencesAction = new QAction(this);
  _preferencesAction->setEnabled(true);
  _preferencesAction->setText(tr("Preferences..."));
  _preferencesAction->setIcon(QIcon(":/images/icon/preferences"));
  _preferencesAction->setShortcut(QKeySequence("Ctrl+P"));

  // report action
  _reportAction = new QAction(this);
  _reportAction->setEnabled(true);
  _reportAction->setText(tr("Report Bug..."));
  _reportAction->setIcon(QIcon(":/images/icon/report"));

  // about action
  _aboutAction = new QAction(this);
  _aboutAction->setEnabled(true);
  _aboutAction->setText(tr("About..."));
  _aboutAction->setIcon(QIcon(":/images/icon/about"));

  // view action group
  _viewActionGroup = new QActionGroup(this);
  _viewActionGroup->setEnabled(true);
  _viewActionGroup->setExclusive(true);

  _viewActionGroup->addAction(_sketchAction);
  _viewActionGroup->addAction(_authorAction);
  _viewActionGroup->addAction(_narrativeAction);
}

void  QisbMainWindow::createMenus()
{
  // file menu
  _fileMenu = menuBar()->addMenu(tr("File"));
  _fileMenu->addAction(_newAction);
  _fileMenu->addAction(_openAction);
  _fileMenu->addSeparator();
  _fileMenu->addAction(_saveAction);
  _fileMenu->addAction(_saveAsAction);
  _fileMenu->addSeparator();
  _fileMenu->addAction(_exportAction);
  _fileMenu->addAction(_importAction);
  _fileMenu->addSeparator();
  _fileMenu->addAction(_closeAction);
  _fileMenu->addSeparator();
  _fileMenu->addAction(_quitAction);

  // edit menu
  _editMenu = menuBar()->addMenu(tr("Edit"));
  _editMenu->addAction(_undoAction);
  _editMenu->addAction(_redoAction);
  _editMenu->addSeparator();
  _editMenu->addAction(_cutAction);
  _editMenu->addAction(_copyAction);
  _editMenu->addAction(_pasteAction);

  // view menu
  _viewMenu = menuBar()->addMenu(tr("View"));
  _viewMenu->addAction(_sketchAction);
  _viewMenu->addAction(_authorAction);
  _viewMenu->addAction(_narrativeAction);

  // window menu
  _windowMenu = menuBar()->addMenu(tr("Window"));

  _windowMenu->addAction(_preferencesAction);

  // help menu
  _helpMenu = menuBar()->addMenu(tr("Help"));
  _helpMenu->addAction(_reportAction);
  _helpMenu->addSeparator();
  _helpMenu->addAction(_aboutAction);
}

void QisbMainWindow::createToolbar()
{
  // file toolbar
  _fileToolbar = addToolBar(tr("File"));

  _fileToolbar->setMovable(true);
  _fileToolbar->setFloatable(false);
  _fileToolbar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

  _fileToolbar->addAction(_newAction);
  _fileToolbar->addAction(_openAction);
  _fileToolbar->addAction(_saveAction);

  // edit toolbar
  _editToolbar = addToolBar(tr("Edit"));

  _editToolbar->setMovable(true);
  _editToolbar->setFloatable(false);
  _editToolbar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

  _editToolbar->addAction(_undoAction);
  _editToolbar->addAction(_redoAction);
  _editToolbar->addAction(_cutAction);
  _editToolbar->addAction(_copyAction);
  _editToolbar->addAction(_pasteAction);

  // view toolbar
  _viewToolbar = addToolBar(tr("View"));

  _viewToolbar->setMovable(true);
  _viewToolbar->setFloatable(false);
  _viewToolbar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

  _viewToolbar->addAction(_sketchAction);
  _viewToolbar->addAction(_authorAction);
  _viewToolbar->addAction(_narrativeAction);

#ifdef Q_OS_MACX
  setUnifiedTitleAndToolBarOnMac(true);
#endif
}

void QisbMainWindow::createWidgets()
{
  _sketch = new QisbSketchWindow(this);
  _author = new QisbAuthorWindow(this);
  _narrative = new QisbNarrativeWindow(this);

  _editor = new QisbEditor(this);
  _editor->insertWindow(_sketch);
  _editor->insertWindow(_author);
  _editor->insertWindow(_narrative);
  _editor->selectWindow(_sketch);

  setCentralWidget(_editor);
}

void  QisbMainWindow::createConnections()
{
  connect(_newAction, SIGNAL(triggered()), SLOT(performNew()));
  connect(_openAction, SIGNAL(triggered()), SLOT(performOpen()));
  connect(_saveAction, SIGNAL(triggered()), SLOT(performSave()));
  connect(_saveAsAction, SIGNAL(triggered()), SLOT(performSaveAs()));
  connect(_exportAction, SIGNAL(triggered()), SLOT(performExport()));
  connect(_importAction, SIGNAL(triggered()), SLOT(performImport()));
  connect(_closeAction, SIGNAL(triggered()), SLOT(performClose()));
  connect(_quitAction, SIGNAL(triggered()), SLOT(performQuit()));
  connect(_undoAction, SIGNAL(triggered()), SLOT(performUndo()));
  connect(_redoAction, SIGNAL(triggered()), SLOT(performRedo()));
  connect(_cutAction, SIGNAL(triggered()), SLOT(performCut()));
  connect(_copyAction, SIGNAL(triggered()), SLOT(performCopy()));
  connect(_pasteAction, SIGNAL(triggered()), SLOT(performPaste()));
  connect(_sketchAction, SIGNAL(triggered()), SLOT(performSketch()));
  connect(_authorAction, SIGNAL(triggered()), SLOT(performAuthor()));
  connect(_narrativeAction, SIGNAL(triggered()), SLOT(performNarrative()));
  connect(_preferencesAction, SIGNAL(triggered()), SLOT(performPreferences()));
  connect(_reportAction, SIGNAL(triggered()), SLOT(performReport()));
  connect(_aboutAction, SIGNAL(triggered()), SLOT(performAbout()));
}

void QisbMainWindow::performNew()
{
  qDebug() << "[ISB]" << ":" << "Performing 'New' action";

  // TODO
}

void QisbMainWindow::performOpen()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Open' action";

  // TODO
}

void QisbMainWindow::performSave()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Save' action";

  // TODO
}

void QisbMainWindow::performSaveAs()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Save As' action";

  // TODO
}


void QisbMainWindow::performExport()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Export' action";

  // TODO
}

void QisbMainWindow::performImport()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Import' action";

  // TODO
}

void QisbMainWindow::performClose()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Close' action";

  // TODO
}

void QisbMainWindow::performQuit()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Quit' action";

  // TODO
}

void QisbMainWindow::performUndo()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Undo' action";

  _editor->undo();
}

void QisbMainWindow::performRedo()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Redo' action";

  _editor->redo();
}

void QisbMainWindow::performCut()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Cut' action";

  // TODO
}

void QisbMainWindow::performCopy()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Copy' action";

  // TODO
}

void QisbMainWindow::performPaste()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Paste' action";

  // TODO
}

void QisbMainWindow::performSketch()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Sketch' action";

  _editor->selectWindow(_sketch);
}

void QisbMainWindow::performAuthor()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Author' action";

  _editor->selectWindow(_author);
}

void QisbMainWindow::performNarrative()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Narrative' action";

  _editor->selectWindow(_narrative);
}

void QisbMainWindow::performPreferences()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Preferences' action";

  // TODO
}

void QisbMainWindow::performReport()
{
  qDebug() << "[ISB]" << ":" << "Performing 'Report' action";

  // TODO
}

void QisbMainWindow::performAbout()
{
  qDebug() << "[ISB]" << ":" << "Performing 'About' action";

  // TODO
}
