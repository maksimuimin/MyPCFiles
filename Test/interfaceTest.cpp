<<<<<<< HEAD
#include <stdlib.h>
#include <iostream>
#include "catch.h"
#include "../MyPCFiles-client/mainwindow.h"
#include <QtCore>


int main(){
	print("Hello world");
	return 0;
=======
#include "catch.h"
#include <../MyPCFiles-client/server.h>

#define CATCH_CONFIG_MAIN

TEST_CASE("Server class") {

    // if there is no such kind of class test will fail
    Server server("username", "host", 8080);
    // if there is no connect method function will fail
    server.connect();
    // if there is no disconnect method function will fail
    server.disconnect();
    // if there is no destructor test will fail
    server.~Server();
>>>>>>> origin/AlexLarutin
}
