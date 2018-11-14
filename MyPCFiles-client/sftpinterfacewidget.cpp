//
// Created by jahongir on 28/10/18.
//
#include "sftpinterfacewidget.h"

SFTPInterfaceWidget::SFTPInterfaceWidget(QWidget* parent, SFTPInterface* _interface) {
    // TODO default constructor
    //Необходимо построить интерфейс взаимодействия пользователя с удалённой файловой системой
    //Необходимые функции:
    //1)Смена директории
    //2)Скачать файл с сервера
    //3)Загрузить файл на сервер
    //Эти функции реализуются слотами, сигналы для которых идут из FileListWidget
}

void SFTPInterfaceWidget::open_connection() {
    // TODO open directory
    // Необходимо вызвать функцию open_connection() класса SFTPInterface
}

void SFTPInterfaceWidget::close_connection() {
    // TODO close directory
    // Необходимо вызвать функцию close_connection() класса SFTPInterface
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
}

