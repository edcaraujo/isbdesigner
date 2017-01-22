#ifndef QISBMAINWINDOW_H
#define QISBMAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QActionGroup>
#include <QToolBar>
#include <QPushButton>

#include <QDebug>

#include "qisbeditor.h"
#include "qisbwelcomewindow.h"
#include "qisbsketchwindow.h"
#include "qisbauthorwindow.h"
#include "qisblivewindow.h"
#include "qisbnarrativewindow.h"
#include "qisbsummarywindow.h"

class QisbMainWindow : public QMainWindow
{
  Q_OBJECT

public:
  QisbMainWindow(QWidget* parent = 0);
  virtual ~QisbMainWindow();

protected slots:
  void performNew();
  void performOpen();
  void performSave();
  void performSaveAs();
  void performExport();
  void performImport();
  void performClose();
  void performQuit();
  void performUndo();
  void performRedo();
  void performCut();
  void performCopy();
  void performPaste();
  void performSketch();
  void performAuthor();
  void performNarrative();
  void performPreferences();
  void performReport();
  void performAbout();

private:
  void createMenus();
  void createActions();
  void createToolbar();
  void createWidgets();
  void createConnections();

  QMenu* _fileMenu;
  QMenu* _editMenu;
  QMenu* _viewMenu;
  QMenu* _windowMenu;
  QMenu* _helpMenu;

  QToolBar* _fileToolbar;
  QToolBar* _editToolbar;
  QToolBar* _viewToolbar;

  QAction* _newAction;
  QAction* _openAction;
  QAction* _saveAction;
  QAction* _saveAsAction;
  QAction* _importAction;
  QAction* _exportAction;
  QAction* _closeAction;
  QAction* _quitAction;
  QAction* _undoAction;
  QAction* _redoAction;
  QAction* _cutAction;
  QAction* _copyAction;
  QAction* _pasteAction;
  QAction* _sketchAction;
  QAction* _authorAction;
  QAction* _narrativeAction;
  QAction* _preferencesAction;
  QAction* _reportAction;
  QAction* _aboutAction;

  QActionGroup* _viewActionGroup;

  QisbWindow* _sketch;
  QisbWindow* _author;
  QisbWindow* _narrative;

  QisbEditor* _editor;
};

#endif // QISBMAINWINDOW_H
