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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/libssh/0.8.4/lib/release/ -lssh.4.7.1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/libssh/0.8.4/lib/debug/ -lssh.4.7.1
else:unix: LIBS += -L$$PWD/../../../../../usr/local/Cellar/libssh/0.8.4/lib/ -lssh.4.7.1

INCLUDEPATH += $$PWD/../../../../../usr/local/Cellar/libssh/0.8.4/include
DEPENDPATH += $$PWD/../../../../../usr/local/Cellar/libssh/0.8.4/include
