#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include "../MyPCFiles-client/fileslistwidget.h";
#include "../MyPCFiles-client/sftpinterfacewidget.h";
#include "../MyPCFiles-client/mainwindow.h";
#include "../MyPCFiles-client/serverlistwidget.h";

using namespace std;

TEST_CASE("FileListWidget class") {

    SECTION("check existence of public methods") {

        // if there is no such kind of class test will fail
        FilesListWidget filesListWidget;
        // if there is no add method function will fail
        filesListWidget.add();
        // If there is no destructor test will fail
        filesListWidget.~FilesListWidget();

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