#ifndef QISBSETTINGS_H
#define QISBSETTINGS_H

#include <QSettings>

class QisbSettings : public QSettings
{
public:
  QisbSettings();
  virtual ~QisbSettings();
};

#endif // QISBSETTINGS_H
