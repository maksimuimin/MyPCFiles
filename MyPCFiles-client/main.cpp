#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //Вобщем случае, здесь писать ничего не надо
    //Возможно, сюда будут вынесены связи сигналов-слотов, но это обсуждается отдельно
    return a.exec();
}
