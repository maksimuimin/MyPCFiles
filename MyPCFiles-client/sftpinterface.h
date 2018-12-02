#ifndef SFTPINTERFACE_H
#define SFTPINTERFACE_H

#include <QList>
#include "server.h"
#include "string"
#include <sys/stat.h>
#include <fcntl.h>

using std::string;

class SFTPInterface {
private:
    Server* server;
    QList<sftp_attributes> files;
    string nameDir;

public:
    SFTPInterface(Server* _server = nullptr): server(_server) {}//TODO заменить указатель на умный из stl
    SFTPInterface(const SFTPInterface&) = delete;
    SFTPInterface(SFTPInterface&&) = delete;
    ~SFTPInterface();

    SFTPInterface&operator=(const SFTPInterface&) = delete;
    SFTPInterface&operator=(SFTPInterface&&) = delete;

    void open_connection();
    void close_connection();
    void changeDir(string path);
    void upload(string, string);
    void download(string);
};

#endif // SFTPINTERFACE_H
