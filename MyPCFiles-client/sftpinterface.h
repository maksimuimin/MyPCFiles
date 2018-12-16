#ifndef SFTPINTERFACE_H
#define SFTPINTERFACE_H

#include <QList>
#include "server.h"
#include "string"
#include <sys/stat.h>
#include <fcntl.h>

using std::string;
using std::shared_ptr;

class SFTPInterface {
private:
    shared_ptr<Server> server;
    QList<sftp_attributes> files;
    string nameDir;

public:
    SFTPInterface(shared_ptr<Server> _server = nullptr): server(std::move(_server)) {}//TODO заменить указатель на умный из stl
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
