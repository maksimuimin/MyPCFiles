#include "mainwindow.h"
#include <QApplication>
#include <QPalette>

//#include <boost/log/core.hpp>
//#include <boost/log/trivial.hpp>
//#include <boost/log/expressions.hpp>
//#include <boost/log/utility/setup/file.hpp>

//namespace logging = boost::log;

//void init()
//{
//    logging::add_file_log(QFile(":/log/default.log").fileName().toStdString());
//    logging::add_file_log("~/dz_3/MyPCFiles/MyPCFiles-client/log/default.log");

//    logging::core::get()->set_filter
//    (
//        logging::trivial::severity >= logging::trivial::info
//    );
//}


int main(int argc, char *argv[]){

//    init();

    BOOST_LOG_TRIVIAL(info) << "PROGRAMM STARTED";

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
    BOOST_LOG_TRIVIAL(info) << "PROGRAMM TERMINATED";
    return a.exec();
}
