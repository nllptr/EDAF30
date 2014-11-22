TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    word.cpp \
    dictionary.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    word.h \
    dictionary.h

