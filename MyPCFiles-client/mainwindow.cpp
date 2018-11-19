#include "mainwindow.h"

MainWindow::MainWindow(): QWidget(){
    //TODO write default constructor
    //Необходимо отобразить основное окно приложения
    //Окно содержит следующие элементы:
    //1)Меню
    //2)Список серверов пользователя
    //3)Кнопку добавления нового сервера в список

    this->setWindowTitle("MyPCFiles");

    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(60, 69, 86));
    pal.setColor(QPalette::Base, QColor(60, 69, 86));
    pal.setColor(QPalette::ButtonText, Qt::white);
    pal.setColor(QPalette::Button, QColor(255,165,0));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    navbar = new NavbarWidget(this);

    logo = new QLabel(this);
    logo->setPixmap(QPixmap(":img/logo.png"));//TODO

    serverList = new ServerListWidget(QVector<Server>(), this);

    addServerBtn = new QPushButton("Add new server", this);
    connect(addServerBtn, SIGNAL(clicked()), this, SLOT(addServerBtnOnClick()));

    mainLayout = new QVBoxLayout(this);
    mainLayout->setMenuBar(navbar);
    mainLayout->addWidget(logo, 0, Qt::AlignmentFlag::AlignHCenter);
    mainLayout->addWidget(serverList);
    mainLayout->addWidget(addServerBtn);
    mainLayout->addStretch();

}

MainWindow::~MainWindow(){
    //TODO write default destructor
    //В деструкторе необходимо освободить всю память, запрошенную приложением у ОС
    //Также необходимо закрыть все открытые ssh соединения, перед этим следует создать диалог, запрашивающий подтверждение у пользователя
    delete navbar;
    delete logo;
    delete serverList;
    delete addServerBtn;
    delete mainLayout;
}

void MainWindow::addServerBtnOnClick(){
    //TODO add server to server list
    //Слот, вызываемый по нажатию кнопки добавления нового сервера
    //Необходимо создать диалог, запрашивающий у пользователя все необходимые данные
    //Затем необходимо корректно вызвать функцию add() класса ServerList
}
