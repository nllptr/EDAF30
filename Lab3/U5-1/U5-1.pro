TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    kvadrat.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    kvadrat.h

