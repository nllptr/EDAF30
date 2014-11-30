TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bostad.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    rum.h \
    bostad.h

