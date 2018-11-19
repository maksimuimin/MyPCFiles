#include "navbarwidget.h"

NavbarWidget::NavbarWidget(QWidget* parent): QMenuBar(parent){
    //TODO write constructor
    //Необходимо создать меню и заполнить его элементами
   settings = new QMenu("Settings",this);
   settings->setIcon(QIcon(":/images/settings.png"));
   connect(settings,SIGNAL(triggered(settings->defaultAction())),this,SLOT(settings_menu_on_click()));
   this->addMenu(settings);
}

NavbarWidget::~NavbarWidget(){
    //TODO write destructor
    //Необходимо освободить всю динамическую память
    delete settings;
}

void NavbarWidget::settings_menu_on_click(){
    //TODO сделать диалог с настройками приложения
    QMessageBox message(this);
    message.setModal(true);
    message.setWindowTitle("Application settings");
    message.setText("Some settings stuff here");
    message.show();
}
