#include <stdlib.h>
#include <iostream>
#include "catch.h"
#include "../MyPCFiles-client/mainwindow.h"
#include <../MyPCFiles-client/server.h>
#include "../MyPCFiles-client/filelistwidget.h";
#include "../MyPCFiles-client/sftpinterfacewidget.h";
#include "../MyPCFiles-client/serverlistwidget.h";

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

TEST_CASE("Server class") {

    // if there is no such kind of class test will fail
    Server server("username", "host", 8080);
    // if there is no connect method function will fail
    server.connect();
    // if there is no disconnect method function will fail
    server.disconnect();
    // if there is no destructor test will fail
    server.~Server();
}

TEST_CASE("FileListWidget class") {

    SECTION("check existence of public methods") {

        // if there is no such kind of class test will fail
        FileListWidget fileListWidget;
        // if there is no add method function will fail
        fileListWidget.add();
        // If there is no destructor test will fail
        fileListWidget.~FileListWidget();

    }
}

TEST_CASE("SFTPInterfaceWidget class") {

    SECTION("check existence of public methods") {

        QWidget* parent = nullptr;
        Server*  server = nullptr;

        SFTPInterfaceWidget sftpInterfaceWidget(parent, server);

        sftpInterfaceWidget.open("/user/data/");
        sftpInterfaceWidget.close();
        sftpInterfaceWidget.changeDir();
        sftpInterfaceWidget.upload();
        sftpInterfaceWidget.download();

        sftpInterfaceWidget.~SFTPInterfaceWidget();

    }
}

TEST_CASE("NavbarWidget class") {

    SECTION("check existence of public methods") {

        QWidget* parent = nullptr;
        NavbarWidget navbarWidget(parent);

        navbarWidget.~NavbarWidget();

    }
}

TEST_CASE("MainWindow class") {

    SECTION("check existence of public methods") {

        QWidget* parent = nullptr;
        MainWindow mainWidget(parent);

        mainWidget.addServerBtnOnClick();
        mainWidget.~MainWindow();

    }
}

TEST_CASE("ServerListWidget class") {

    SECTION("check existence of public methods") {

        QWidget* parent = nullptr;
        Server server;

        ServerListWidget serverListWidget(parent);

        serverListWidget.add(server);
        serverListWidget.remove(15);
        serverListWidget.change("localhost", 22, "username");

        serverListWidget.~ServerListWidget();

    }
}
