QT       -= gui

TARGET = consoleapp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Menu.cpp \
    Vector.cpp \
    gauss_counting.cpp

HEADERS += \
    Menu.h \
    Vector.h \
    gauss_counting.h
