#include "qisbwindow.h"

QisbWindow::QisbWindow(QWidget* parent)
  : QMainWindow(parent)
{
  setId("UNK");
  setTitle("Unknow View");
}

QisbWindow::~QisbWindow()
{

}

QString QisbWindow::getId()
{
  return _id;
}

void QisbWindow::setId(QString id)
{
  _id = id;
}

QString QisbWindow::getTitle()
{
  return _title;
}

void QisbWindow::setTitle(QString title)
{
  _title = title;
}

