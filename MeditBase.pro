#-------------------------------------------------
#
# Project created by QtCreator 2015-05-07T18:56:53
#
#-------------------------------------------------

QT       -= core gui

TARGET = MeditBase
TEMPLATE = lib

DEFINES += MEDITBASE_LIBRARY

SOURCES += \
    src/medit/meditbase/event/Event.cpp \
    src/medit/meditbase/event/test.cpp \
    src/medit/meditbase/base.cpp \
    src/medit/meditbase/IdGenerator.cpp

HEADERS += \
    src/medit/meditbase/event/AbstractDispatcher.hpp \
    src/medit/meditbase/event/Event.hpp \
    src/medit/meditbase/event/EventHandler.hpp \
    src/medit/meditbase/event/IDispatcherAware.hpp \
    src/medit/meditbase/event/SingleDispatcher.hpp \
    src/medit/meditbase/base.hpp \
    src/medit/meditbase/interface/IClonable.hpp \
    src/medit/meditbase/IdGenerator.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
