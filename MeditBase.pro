#-------------------------------------------------
#
# Project created by QtCreator 2015-05-07T18:56:53
#
#-------------------------------------------------

QT       -= core gui

TARGET = MeditBase
TEMPLATE = lib

DEFINES += MEDITBASE_LIBRARY

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    src/medit/meditbase/event/Event.cpp \
    src/medit/meditbase/base.cpp \
    src/medit/meditbase/IdGenerator.cpp \
    src/medit/meditbase/di/ServiceLocator.cpp \
    src/medit/meditbase/di/ServiceLocatorAware.cpp \
    src/medit/meditbase/di/AbstractServiceContainer.cpp

HEADERS += \
    src/medit/meditbase/event/AbstractDispatcher.hpp \
    src/medit/meditbase/event/Event.hpp \
    src/medit/meditbase/event/EventHandler.hpp \
    src/medit/meditbase/event/IDispatcherAware.hpp \
    src/medit/meditbase/event/SingleDispatcher.hpp \
    src/medit/meditbase/base.hpp \
    src/medit/meditbase/interface/IClonable.hpp \
    src/medit/meditbase/IdGenerator.hpp \
    src/medit/meditbase/di/ServiceLocator.hpp \
    src/medit/meditbase/di/ServiceContainer.hpp \
    src/medit/meditbase/di/ServiceLocatorAware.hpp \
    src/medit/meditbase/di/AbstractServiceContainer.hpp \
    src/medit/meditbase/Allocator.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
