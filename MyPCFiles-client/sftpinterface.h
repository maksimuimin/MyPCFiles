#ifndef SFTPINTERFACE_H
#define SFTPINTERFACE_H

#include <QList>
#include "server.h"

class SFTPInterface {
private:
    Server* server;
    QList<sftp_file> files;
public:
    SFTPInterface(Server* _server = nullptr): server(_server) {}//TODO заменить указатель на умный из stl
    SFTPInterface(const SFTPInterface& other) = delete;
    SFTPInterface(SFTPInterface&& other) = delete;
    ~SFTPInterface();

    SFTPInterface&operator=(const SFTPInterface& other) = delete;
    SFTPInterface&operator=(SFTPInterface&& other) = delete;

    void open_connection();
    void close_connection();
    void changeDir();
    void upload();
    void download();
};

#endif // SFTPINTERFACE_H
