TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mynt.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    mynt.h

