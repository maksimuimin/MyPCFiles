#-------------------------------------------------
#
# Project created by QtCreator 2018-10-28T21:26:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyPCFiles-client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        navbarwidget.cpp \
        serverlistwidget.cpp \
        server.cpp \
        sftpinterfacewidget.cpp \
    filelistwidget.cpp \
    sftpinterface.cpp \
    serverlist.cpp

HEADERS += \
        mainwindow.h \
        navbarwidget.h \
        serverlistwidget.h \
        server.h \
        sftpinterfacewidget.h \
    filelistwidget.h \
    sftpinterface.h \
    serverlist.h

HEADERS += \
        mainwindow.h \
    sftpinterfacewidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS +=

LIBS += -L/usr/lib -lssh

DISTFILES +=

RESOURCES += \
    res.qrc


unix:!macx: LIBS += -L$$PWD/../../../../../usr/lib/ -lssh

DEPENDPATH += $$PWD/../../../../../usr/include

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lboost_date_time
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libboost_date_time.a

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lboost_log

DEPENDPATH += $$PWD/../../../../../usr/local/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libboost_log.a

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lboost_log_setup
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libboost_log_setup.a

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lboost_filesystem
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libboost_filesystem.a

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lboost_system
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libboost_system.a

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lboost_thread
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libboost_thread.a

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lboost_chrono
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libboost_chrono.a
