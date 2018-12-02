#include "navbarwidget.h"

NavbarWidget::NavbarWidget(QWidget* parent): QMenuBar(parent){
    //TODO write constructor
    //Необходимо создать меню и заполнить его элементами
    QPalette  pal = palette();
    pal.setColor(QPalette::ButtonText, Qt::white);
    this->setPalette(pal);

    QAction* settings = this->addAction("Settings");
    settings->connect(settings,SIGNAL(triggered()), this,SLOT(settings_menu_on_click()));
}

void NavbarWidget::settings_menu_on_click(){
    //TODO сделать диалог с настройками приложения
    QMessageBox message(this);
    message.setModal(true);
    message.setWindowTitle("Application settings");
    message.setText("Some global settings stuff here");
    message.exec();
}
