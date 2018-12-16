//#include "../MyPCFiles-client/mainwindow.h"
//#include "../MyPCFiles-client/filelistwidget.h";
//#include "../MyPCFiles-client/serverlistwidget.h";
#include "../server.h"
#include "../sftpinterface.h"
#include <QtTest>

class Test: public QObject
{
    Q_OBJECT
private slots:

    void ServerTest() {
        class Server server("demo", "password", "test.rebex.net", 22, "Test.rebex.net");

        SFTPInterface sftpinterface(&server);
        sftpinterface.open_connection();
        sftpinterface.changeDir("/");
        sftpinterface.download("readme.txt");
        sftpinterface.close_connection();
    }

};

QTEST_MAIN(Test)
#include "interfaceTest.moc"


//TEST_CASE("FileListWidget class") {

//    SECTION("check existence of public methods") {

//        // if there is no such kind of class test will fail
//        FileListWidget fileListWidget;
//        // if there is no add method function will fail
//        fileListWidget.add();
//        // If there is no destructor test will fail
//        fileListWidget.~FileListWidget();

//    }
//}

//TEST_CASE("SFTPInterfaceWidget class") {

//    SECTION("check existence of public methods") {

//        QWidget* parent = nullptr;
//        Server*  server = nullptr;

//        SFTPInterfaceWidget sftpInterfaceWidget(parent, server);

//        sftpInterfaceWidget.open("/user/data/");
//        sftpInterfaceWidget.close();
//        sftpInterfaceWidget.changeDir();
//        sftpInterfaceWidget.upload();
//        sftpInterfaceWidget.download();

//        sftpInterfaceWidget.~SFTPInterfaceWidget();

//    }
//}

//TEST_CASE("NavbarWidget class") {

//    SECTION("check existence of public methods") {

//        QWidget* parent = nullptr;
//        NavbarWidget navbarWidget(parent);

//        navbarWidget.~NavbarWidget();

//    }
//}

//TEST_CASE("MainWindow class") {

//    SECTION("check existence of public methods") {

//        QWidget* parent = nullptr;
//        MainWindow mainWidget(parent);

//        mainWidget.addServerBtnOnClick();
//        mainWidget.~MainWindow();

//    }
//}

//TEST_CASE("ServerListWidget class") {

//    SECTION("check existence of public methods") {

//        QWidget* parent = nullptr;
//        Server server;

//        ServerListWidget serverListWidget(parent);

//        serverListWidget.add(server);
//        serverListWidget.remove(15);
//        serverListWidget.change("localhost", 22, "username");

//        serverListWidget.~ServerListWidget();

//    }
//}
