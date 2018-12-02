#include "mainwindow.h"
#include <QApplication>
#include <QPalette>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;

    QPalette pal = w.palette();
    pal.setColor(QPalette::Background, QColor(60, 69, 86));
    pal.setColor(QPalette::Base, QColor(60, 69, 86));
    pal.setColor(QPalette::AlternateBase,QColor(50,55,64));
    pal.setColor(QPalette::ButtonText, Qt::black);
    pal.setColor(QPalette::Button, QColor(255,165,0));
    pal.setColor(QPalette::Text, QColor(255,165,0));
    w.setPalette(pal);

    w.show();
    //Вобщем случае, здесь писать ничего не надо
    //Возможно, сюда будут вынесены связи сигналов-слотов, но это обсуждается отдельно
    return a.exec();
}
