QT += \
  xml \
  widgets

TARGET = \
  isbdesigner

VERSION = \
  0.1.0

DEFINES += \
  VERSION='\\"$${VERSION}-$$system(git log -n 1 --format="%h")\\"'

INCLUDEPATH += \
  src/core \
  src/ui \
  src/ui/view \
  src/ui/view/welcome \
  src/ui/view/sketch \
  src/ui/view/authoring \
  src/ui/view/live \
  src/ui/view/narrative \
  src/ui/view/summary \
  src/util

SOURCES += \
  src/main.cpp \
  src/ui/qisbmainwindow.cpp \
  src/ui/qisbeditor.cpp \
  src/core/qisbentity.cpp \
  src/util/qisbsettings.cpp \
  src/util/qisbutil.cpp \
  src/ui/view/qisbscene.cpp \
  src/ui/view/qisbitem.cpp \
  src/core/qisbcommand.cpp \
  src/core/qisbinsert.cpp \
  src/core/qisbremove.cpp \
  src/core/qisbchange.cpp \
  src/core/qisbselect.cpp \
  src/ui/view/narrative/qisbnarrativesequence.cpp \
  src/ui/view/narrative/qisbnarrativelink.cpp \
  src/ui/view/narrative/qisbnarrativescene.cpp \
  src/ui/view/narrative/qisbnarrativemenu.cpp \
  src/ui/view/qisbwindow.cpp \
  src/ui/view/narrative/qisbnarrativewindow.cpp \
  src/ui/view/qisbview.cpp \
  src/ui/view/narrative/qisbnarrativeview.cpp \
  src/ui/view/live/qisblivewindow.cpp \
  src/ui/view/authoring/qisbauthorwindow.cpp \
  src/ui/view/sketch/qisbsketchwindow.cpp \
  src/ui/view/summary/qisbsummarywindow.cpp \
  src/ui/view/welcome/qisbwelcomewindow.cpp

HEADERS += \
  src/ui/qisbmainwindow.h \
  src/ui/qisbeditor.h \
  src/core/qisbentity.h \
  src/util/qisbsettings.h \
  src/util/qisbutil.h \
  src/ui/view/qisbscene.h \
  src/ui/view/qisbitem.h \
  src/core/qisbcommand.h \
  src/core/qisbinsert.h \
  src/core/qisbremove.h \
  src/core/qisbchange.h \
  src/core/qisbselect.h \
  src/core/qisb.h \
  src/ui/view/narrative/qisbnarrativesequence.h \
  src/ui/view/narrative/qisbnarrativelink.h \
  src/ui/view/narrative/qisbnarrativescene.h \
  src/ui/view/narrative/qisbnarrativemenu.h \
  src/ui/view/qisbwindow.h \
  src/ui/view/narrative/qisbnarrativewindow.h \
  src/ui/view/qisbview.h \
  src/ui/view/narrative/qisbnarrativeview.h \
  src/ui/view/welcome/qisbwelcomewindow.h \
  src/ui/view/summary/qisbsummarywindow.h \
  src/ui/view/sketch/qisbsketchwindow.h \
  src/ui/view/live/qisblivewindow.h \
  src/ui/view/authoring/qisbauthorwindow.h

RESOURCES += \
  application.qrc
