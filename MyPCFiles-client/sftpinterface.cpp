#include "sftpinterface.h"

SFTPInterface::~SFTPInterface() {
    //Необходимо освободить всю динамическую память
}

void SFTPInterface::open_connection(){
    //Необходимо открыть соединение с сервером
    //Для этого необходимо вызвать метод connect сервера
    server->connect();
}

void SFTPInterface::close_connection(){
    //Необходимо закрыть соединение с сервером
    //Для этого необходимо вызвать метод disconnect сервера
    server->disconnect();
}

void SFTPInterface::changeDir(){
    //Необходимо сменить директорию на сервере
    //Подробнее см. документацию libssh
}

void SFTPInterface::upload(){
    //Необходимо загрузить файл на сервер
    //Подробнее см. документацию libssh
}

void SFTPInterface::download(){
    //Необходимо скачать файл с сервера
    //Подробнее см. документацию libssh
}
