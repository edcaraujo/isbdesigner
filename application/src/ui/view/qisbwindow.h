#ifndef QISBWINDOW_H
#define QISBWINDOW_H

#include <QMainWindow>
#include <QMap>

#include <QDebug>

class QisbWindow : public QMainWindow
{
  Q_OBJECT

public:
  QisbWindow(QWidget* parent = 0);
  virtual ~QisbWindow();

  QString getId();
  void setId(QString id);

  QString getTitle();
  void setTitle(QString title);

public slots:
  virtual void insert(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings) = 0;
  virtual void remove(const QString &uid, const QMap<QString, QString> &settings) = 0;
  virtual void change(const QString &uid, const QMap<QString, QString> &properties, const QMap<QString, QString> &previous, const QMap<QString, QString> &settings) = 0;
  virtual void select(const QString &uid, const QMap<QString, QString> &settings) = 0;

signals:
  void inserted(const QString &uid, const QString &parent, const QMap<QString, QString> &properties, const QMap<QString, QString> &settings);
  void removed(const QString &uid, const QMap<QString, QString> &settings);
  void changed(const QString &uid, const QMap<QString, QString> &properties, const QMap<QString, QString> &previous, const QMap<QString, QString> &settings);
  void selected(const QString &uid, const QMap<QString, QString> &settings);

private:
  QString _id;
  QString _title;
};

#endif // QISBWINDOW_H
