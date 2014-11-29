TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pet.cpp \
    dog.cpp \
    cat.cpp \
    bird.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    pet.h \
    dog.h \
    cat.h \
    bird.h

