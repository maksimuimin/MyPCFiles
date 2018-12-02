#include "sftpinterface.h"
#define MAX_XFER_BUF_SIZE 16384

SFTPInterface::~SFTPInterface() {
    //Необходимо освободить всю динамическую память
}

void SFTPInterface::open_connection(){
    //Необходимо открыть соединение с сервером
    //Для этого необходимо вызвать метод connect сервера
}

void SFTPInterface::close_connection(){
    //Необходимо закрыть соединение с сервером
    //Для этого необходимо вызвать метод disconnect сервера
}

void SFTPInterface::changeDir(){
    //Необходимо сменить директорию на сервере
    //Подробнее см. документацию libssh
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
     
     
     file = sftp_open(server->getSftp(), PCDir, access_type, 0);
     
     if (file == NULL) {
         QString errorMsg = server->strConcat(3, "Can't open file for reading: ", serverDir, ssh_get_error(server->getSsh()));
         server->showErrorDialog(errorMsg);
         return;
     }
     
     serverDir = serverDir + "/" + fileName;
     
     fd = open(serverDir, O_CREAT);
     if (fd < 0) {
         QString errorMsg = server->strConcat(3, "Can't open file for writing: ", serverDir, ssh_get_error(server->getSsh()));
         server->showErrorDialog(errorMsg);
         return;
     }
     
     for (;;) {
         nbytes = sftp_read(file, buffer, sizeof(buffer));
         if (nbytes == 0) {
             break; // EOF
         } else if (nbytes < 0) {
             QString errorMsg = server->strConcat(3, "Error while reading file: ", serverDir, ssh_get_error(server->getSsh()));
             sftp_close(file);
             server->showErrorDialog(errorMsg);
             return;
         }
         
         nwritten = write(fd, buffer, nbytes);
         if (nwritten != nbytes) {
             QString errorMsg = server->strConcat(3, "Error writing: ", serverDir, ssh_get_error(server->getSsh()));
             server->showErrorDialog(errorMsg);
             sftp_close(file);
             return;
         }
     }
     
     rc = sftp_close(file);
     if (rc != SSH_OK) {
         QString errorMsg = server->strConcat(3, "Can't close the read file: ", serverDir, ssh_get_error(server->getSsh()));
         server->showErrorDialog(errorMsg);
         return;
     }
     return;
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
     
     
     file = sftp_open(server->getSftp(), serverDir, access_type, 0);
     
     if (file == NULL) {
         QString errorMsg = server->strConcat(3, "Can't open file for reading: ", serverDir, ssh_get_error(server->getSsh()));
         server->showErrorDialog(errorMsg);
         return;
     }
     
     string PCDir = "~/Downloads/" + fileName;
     
     fd = open(PCDir, O_CREAT);
     if (fd < 0) {
         QString errorMsg = server->strConcat(3, "Can't open file for writing: ", serverDir, ssh_get_error(server->getSsh()));
         server->showErrorDialog(errorMsg);
         return;
     }
     
     for (;;) {
         nbytes = sftp_read(file, buffer, sizeof(buffer));
         if (nbytes == 0) {
             break; // EOF
         } else if (nbytes < 0) {
             QString errorMsg = server->strConcat(3, "Error while reading file: ", serverDir, ssh_get_error(server->getSsh()));
             sftp_close(file);
             server->showErrorDialog(errorMsg);
             return;
         }
         
         nwritten = write(fd, buffer, nbytes);
         if (nwritten != nbytes) {
             QString errorMsg = server->strConcat(3, "Error writing: ", serverDir, ssh_get_error(server->getSsh()));
             server->showErrorDialog(errorMsg);
             sftp_close(file);
             return;
         }
     }
     
     rc = sftp_close(file);
     if (rc != SSH_OK) {
         QString errorMsg = server->strConcat(3, "Can't close the read file: ", serverDir, ssh_get_error(server->getSsh()));
         server->showErrorDialog(errorMsg);
         return;
     }
     return;
}
