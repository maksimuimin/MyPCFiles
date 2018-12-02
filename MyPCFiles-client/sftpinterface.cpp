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

void SFTPInterface::changeDir(string path){
    //Необходимо сменить директорию на сервере
    //Подробнее см. документацию libssh
    sftp_dir dir;
    sftp_attributes attributes;
    int rc;

    dir = sftp_opendir(server->getSftp(), path.c_str());

    if (!dir) {
        QString errorMsg = server->strConcat(2, "Directory not opened: ",
                                     ssh_get_error(server->getSsh()));
        server->showErrorDialog(errorMsg);
        return;
    }

    if (!sftp_dir_eof(dir)) {
        QString errorMsg = server->strConcat(2, "Can't list directory: ",
                                     ssh_get_error(server->getSsh()));
        server->showErrorDialog(errorMsg);
        sftp_closedir(dir);
        return;
    }

    while ((attributes = sftp_readdir(server->getSftp(), dir)) != NULL)
        files.push_back(attributes);

    rc = sftp_closedir(dir);
    if (rc != SSH_OK) {
        QString errorMsg = server->strConcat(2, "Can't close directory: ",
                                     ssh_get_error(server->getSsh()));
        server->showErrorDialog(errorMsg);
        return;
    }
}

void SFTPInterface::upload(){
    //Необходимо загрузить файл на сервер
    //Подробнее см. документацию libssh
}

void SFTPInterface::download(){
    //Необходимо скачать файл с сервера
    //Подробнее см. документацию libssh
}
