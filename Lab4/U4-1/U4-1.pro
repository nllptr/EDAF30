TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vektor.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    vektor.h

