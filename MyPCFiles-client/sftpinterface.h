#ifndef SFTPINTERFACE_H
#define SFTPINTERFACE_H

#include <QList>
#include "server.h"

class SFTPInterface {
private:
    Server* server;
    QList<sftp_file> files;
public:
    SFTPInterface(SFTPInterface* _interface = nullptr);
    SFTPInterface(const SFTPInterface& other) = delete;
    SFTPInterface(SFTPInterface&& other) = delete;
    ~SFTPInterface();

    SFTPInterface&operator=(const SFTPInterface& other) = delete;
    SFTPInterface&operator=(SFTPInterface&& other) = delete;

    void open();
    void close();
    void changeDir();
    void upload();
    void download();
};

#endif // SFTPINTERFACE_H
