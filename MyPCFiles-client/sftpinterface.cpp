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
    BOOST_LOG_TRIVIAL(info) << "Command change dir to " << path;
    sftp_dir dir;
    sftp_attributes attributes;
    int rc;
    dir = sftp_opendir(server->getSftp(), path.c_str());
    if (!dir) {
        BOOST_LOG_TRIVIAL(error) << "Directory not opened: " << ssh_get_error(server->getSsh());
        Server::SERVER_ERROR(2, "Directory not opened: ",
                                     ssh_get_error(server->getSsh()));
        return;
    }

    while ((attributes = sftp_readdir(server->getSftp(), dir)) != nullptr) {
        BOOST_LOG_TRIVIAL(info) << "Directory name = " << attributes->name;
        files.push_back(attributes);
    }

    if (!sftp_dir_eof(dir)) {
        BOOST_LOG_TRIVIAL(error) << "Can't list directory: " << ssh_get_error(server->getSsh());
        sftp_closedir(dir);
        return;
    }

    rc = sftp_closedir(dir);
    if (rc != SSH_OK) {
        BOOST_LOG_TRIVIAL(error) << "Can't close directory: " << ssh_get_error(server->getSsh());
        Server::SERVER_ERROR(2, "Can't close directory: ",
                                     ssh_get_error(server->getSsh()));
        return;
    }
    BOOST_LOG_TRIVIAL(info) << "Changed";
}

void SFTPInterface::upload(string fileName){
    //Необходимо загрузить файл на сервер
    BOOST_LOG_TRIVIAL(info) << "Command upload file: " << fileName;

    sftp_file file;
    char buffer[MAX_XFER_BUF_SIZE];
    int nbytes, nwritten, rc;
    int fd;


    fd = open(fileName.c_str(), O_RDONLY, 0);
    if (fd < 0) {
        BOOST_LOG_TRIVIAL(error) << "Can't open file for reading: " << fileName.c_str() << strerror(errno);
        return;
    }

    file = sftp_open(server->getSftp(), fileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    if (file == nullptr) {
        BOOST_LOG_TRIVIAL(error) << "Can't open file for writing: " << fileName.c_str() << " " <<  ssh_get_error(server->getSsh());
        return;
    }

    for (;;) {

        nbytes = read(fd, buffer, sizeof(buffer));

        if (nbytes == 0) {
            break; // EOF
        } else if (nbytes < 0) {
            BOOST_LOG_TRIVIAL(error) << "Error while reading file: " << fileName.c_str() << strerror(errno);
            close(fd);
            return;
        }

        nwritten = sftp_write(file, buffer, nbytes);
        if (nwritten != nbytes) {
            BOOST_LOG_TRIVIAL(error) << "Error writing: " << fileName.c_str() << " " << ssh_get_error(server->getSsh());
            close(fd);
            return;
        }
    }

    rc = sftp_close(file);
    if (rc != SSH_OK) {
        BOOST_LOG_TRIVIAL(error) << "Can't close the read file: " << fileName.c_str() << ssh_get_error(server->getSsh());
        return;
    }

    close(fd);

    BOOST_LOG_TRIVIAL(info) << "Uploaded " << fileName.c_str();
}

void SFTPInterface::download(string fileName){
    //Необходимо скачать файл с сервера
    BOOST_LOG_TRIVIAL(info) << "Command download file: " << fileName;

    sftp_file file;
    char buffer[MAX_XFER_BUF_SIZE];
    int nbytes, nwritten, rc;
    int fd;
     
     
    file = sftp_open(server->getSftp(), fileName.c_str(), O_RDONLY, 0);

    if (file == nullptr) {
        BOOST_LOG_TRIVIAL(error) << "Can't open file for reading: " << fileName.c_str() << ssh_get_error(server->getSsh());
        return;
    }
     

    string PCDir = "../downloads/" + fileName;

    fd = open(fileName.c_str(),  O_WRONLY | O_CREAT, S_IWRITE | S_IREAD);

    if (fd < 0) {
        BOOST_LOG_TRIVIAL(error) << "Can't open file for writing: " << fileName.c_str() << " " << strerror(errno);
        return;
    }

    for (;;) {
        nbytes = sftp_read(file, buffer, sizeof(buffer));

        if (nbytes == 0) {
            break; // EOF
        } else if (nbytes < 0) {
            BOOST_LOG_TRIVIAL(error) << "Error while reading file: " << fileName.c_str() << strerror(errno);
            sftp_close(file);
        }

        nwritten = write(fd, buffer, nbytes);
        if (nwritten != nbytes) {
            BOOST_LOG_TRIVIAL(error) << "Error writing: " << fileName.c_str() << strerror(errno);
            sftp_close(file);
            return;
        }
    }

    rc = sftp_close(file);
    if (rc != SSH_OK) {
        BOOST_LOG_TRIVIAL(error) << "Can't close the read file: " << fileName.c_str() << ssh_get_error(server->getSsh());
        return;
    }

    close(fd);

    BOOST_LOG_TRIVIAL(info) << "Downloaded in " << fileName.c_str();
}
