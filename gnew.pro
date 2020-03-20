#-------------------------------------------------
#
# Project created by QtCreator 2020-03-06T10:40:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gnew
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
win32: DEFINES+=_USE_MATH_DEFINES

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    formgraph.cpp \
    alcdata.cpp \
    convert.cpp

HEADERS += \
        mainwindow.h \
    formgraph.h \
    alcdata.h \
    convert.h

FORMS += \
        mainwindow.ui \
    formgraph.ui

unix: LIBS += -lqwt-qt5

win32:CONFIG(release, debug|release): LIBS += -Lc:\Qwt-6.1.4\lib -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -Lc:\Qwt-6.1.4\lib\ -lqwtd

win32: INCLUDEPATH += c:\Qwt-6.1.4\include
unix: INCLUDEPATH += /usr/include/qt5/qwt
win32: DEPENDPATH += c:\Qwt-6.1.4\include
