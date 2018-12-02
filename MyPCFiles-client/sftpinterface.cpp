#include "sftpinterface.h"

#define MAX_XFER_BUF_SIZE 16384

SFTPInterface::~SFTPInterface() {
    //Необходимо освободить всю динамическую память
    files.clear();
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
        Server::SERVER_ERROR(2, "Directory not opened: ",
                                     ssh_get_error(server->getSsh()));
        return;
    }

    if (!sftp_dir_eof(dir)) {
        Server::SERVER_ERROR(2, "Can't list directory: ",
                                     ssh_get_error(server->getSsh()));
        sftp_closedir(dir);
        return;
    }

    while ((attributes = sftp_readdir(server->getSftp(), dir)) != NULL)
        files.push_back(attributes);

    rc = sftp_closedir(dir);
    if (rc != SSH_OK) {
        Server::SERVER_ERROR(2, "Can't close directory: ",
                                     ssh_get_error(server->getSsh()));
        return;
    }
}

void SFTPInterface::upload(string serverDir, string fileName){
    //Необходимо загрузить файл на сервер

    int access_type;
    sftp_file file;
    char buffer[MAX_XFER_BUF_SIZE];
    int nbytes, nwritten, rc;
    int fd;

    string PCDir = nameDir + "/" + fileName;
    access_type = O_RDONLY;

    file = sftp_open(server->getSftp(), PCDir.c_str(), access_type, 0);

    if (file == nullptr) {
        Server::SERVER_ERROR(3, "Can't open file for reading: ", serverDir.c_str(), ssh_get_error(server->getSsh()));
        return;
    }

    serverDir = serverDir + "/" + fileName;

    fd = open(serverDir.c_str(), O_CREAT);
    if (fd < 0) {
        Server::SERVER_ERROR(3, "Can't open file for writing: ", serverDir.c_str(), ssh_get_error(server->getSsh()));
        return;
    }

    for (;;) {

        nbytes = sftp_read(file, buffer, sizeof(buffer));

        if (nbytes == 0) {
            break; // EOF
        } else if (nbytes < 0) {
            Server::SERVER_ERROR(3, "Error while reading file: ", serverDir.c_str(), ssh_get_error(server->getSsh()));
            sftp_close(file);
            return;
        }

        nwritten = write(fd, buffer, nbytes);
        if (nwritten != nbytes) {

            Server::SERVER_ERROR(3, "Error writing: ", serverDir.c_str(), ssh_get_error(server->getSsh()));
            sftp_close(file);
            return;
        }
    }

    rc = sftp_close(file);
    if (rc != SSH_OK) {
        Server::SERVER_ERROR(3, "Can't close the read file: ", serverDir.c_str(), ssh_get_error(server->getSsh()));
        return;
    }
}

void SFTPInterface::download(string fileName){
    //Необходимо скачать файл с сервера
    
    int access_type;
    sftp_file file;
    char buffer[MAX_XFER_BUF_SIZE];
    int nbytes, nwritten, rc;
    int fd;
    string serverDir = nameDir + "/" + fileName;
    access_type = O_RDONLY;
     
     
    file = sftp_open(server->getSftp(), serverDir.c_str(), access_type, 0);

    if (file == NULL) {
        Server::SERVER_ERROR(3, "Can't open file for reading: ", serverDir.c_str(), ssh_get_error(server->getSsh()));
        return;
    }
     
    string PCDir = "~/Downloads/" + fileName;

    fd = open(PCDir.c_str(), O_CREAT);
    if (fd < 0) {
        Server::SERVER_ERROR(3, "Can't open file for writing: ", serverDir.c_str(), ssh_get_error(server->getSsh()));
        return;
    }

    for (;;) {
        nbytes = sftp_read(file, buffer, sizeof(buffer));

        if (nbytes == 0) {
            break; // EOF
        } else if (nbytes < 0) {
            Server::SERVER_ERROR(3, "Error while reading file: ", serverDir.c_str(), ssh_get_error(server->getSsh()));
            sftp_close(file);
        }

        nwritten = write(fd, buffer, nbytes);
        if (nwritten != nbytes) {
            Server::SERVER_ERROR(3, "Error writing: ", serverDir.c_str(), ssh_get_error(server->getSsh()));
            sftp_close(file);
            return;
        }
    }

    rc = sftp_close(file);
    if (rc != SSH_OK) {
        Server::SERVER_ERROR(3, "Can't close the read file: ", serverDir.c_str(), ssh_get_error(server->getSsh()));
        return;
    }
}
