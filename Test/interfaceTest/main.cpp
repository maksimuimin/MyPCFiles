#include <QCoreApplication>
#include "../catch.h"
#include "../../MyPCFiles-client/mainwindow.h"
#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    std::cout << "Hello world";

    return a.exec();
}
