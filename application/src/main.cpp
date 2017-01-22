#include <QApplication>
#include <QDebug>

#include "qisbmainwindow.h"
#include "qisbutil.h"
#include "qisbsettings.h"

int main(int argc, char *argv[])
{
  QApplication application(argc, argv);
  application.setApplicationName("isbdesigner");
  application.setApplicationVersion(QString(VERSION));
  application.setOrganizationName("telemidia");
  application.setOrganizationDomain("telemidia.puc-rio.br");

  QisbMainWindow window;
  window.setWindowTitle("ISB Designer (v"+QString(VERSION)+")");
  window.setMinimumWidth(800);
  window.setMinimumHeight(600);
  window.show();

  return application.exec();
}
