TEMPLATE = app
TARGET = FlightManagement
DESTDIR = ../x64/Debug
CONFIG += debug
LIBS += -L"."
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += debug
UI_DIR += .
RCC_DIR += .
include(FlightManagement.pri)
win32:RC_FILE = FlightManagement.rc

msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

QT+= widgets
QT+= sql
