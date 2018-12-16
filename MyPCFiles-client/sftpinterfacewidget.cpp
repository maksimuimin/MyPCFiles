//
// Created by jahongir on 28/10/18.
//
#include "sftpinterfacewidget.h"

SFTPInterfaceWidget::SFTPInterfaceWidget(QWidget* parent, shared_ptr<Server> server) : QDialog(parent),
                                                                                        interface(std::move(server)){
    // TODO default constructor
    //Необходимо построить интерфейс взаимодействия пользователя с удалённой файловой системой
    //Необходимые функции:
    //1)Смена директории
    //2)Скачать файл с сервера
    //3)Загрузить файл на сервер
    //Эти функции реализуются слотами, сигналы для которых идут из FileListWidgetш
    mainLayout = new QVBoxLayout(this);
    filesList = new FileListWidget(this);
    uploadBtn = new QPushButton(QIcon(":img/upload.png"),"",this);
    mainLayout->addWidget(filesList);
    mainLayout->addWidget(uploadBtn);
    connect(uploadBtn,SIGNAL(clicked),this,SLOT(upload()));
}

void SFTPInterfaceWidget::changeDir() {
    // TODO change directory
    // Необходимо вызвать функцию changeDir() класса SFTPInterface
}

void SFTPInterfaceWidget::upload() {
    // TODO upload file from client to server
    // Необходимо вызвать функцию upload() класса SFTPInterface
}

void SFTPInterfaceWidget::download() {
    // TODO download file from server to client
    // Необходимо вызвать функцию download() класса SFTPInterface
}

SFTPInterfaceWidget::~SFTPInterfaceWidget() {
    // TODO destructor
    //Необходимо освободить динамическую память
    delete filesList;
    delete uploadBtn;
    delete mainLayout;
}

