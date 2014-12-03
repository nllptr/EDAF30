TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    personnummer.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    personnummer.h

