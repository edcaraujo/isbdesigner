#include "qisbsettings.h"

QisbSettings::QisbSettings()
  : QSettings(QSettings::IniFormat ,QSettings::UserScope, "telemidia", "isbdesigner")
{

}

QisbSettings::~QisbSettings()
{

}
