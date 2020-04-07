QT += core gui dtkwidget

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = isoCustomizer
TEMPLATE = app

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    chooseiso.cpp \
    choosearchitecture.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    mainwindow.h \
    chooseiso.h \
    choosearchitecture.h
