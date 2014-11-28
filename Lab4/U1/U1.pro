TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    circle.cpp \
    cylinder.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    circle.h \
    cylinder.h

