#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QPalette>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace logging = boost::log;
namespace keywords = boost::log::keywords;

void init() {

    static const std::string COMMON_FMT("[%TimeStamp%][%Severity%]:  %Message%");
    logging::register_simple_formatter_factory< logging::trivial::severity_level, char >("Severity");

    logging::add_file_log(
                keywords::file_name = "../log/default.log",
                keywords::format = COMMON_FMT,
                keywords::auto_flush = true
    );

   logging::core::get()->set_filter (
        logging::trivial::severity >= logging::trivial::info
   );
}


int main(int argc, char *argv[]){

    init();
    logging::add_common_attributes();

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
    return a.exec();
}
