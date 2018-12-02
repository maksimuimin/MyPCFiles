#ifndef SFTPINTERFACE_H
#define SFTPINTERFACE_H

#include <QList>
#include "server.h"
#include "string"

using std::string;

class SFTPInterface {
private:
    Server* server;
    QList<sftp_attributes> files;
    string nameDir;

public:
    SFTPInterface(Server* _server = nullptr): server(_server) {}//TODO заменить указатель на умный из stl
    SFTPInterface(const SFTPInterface& other) = delete;
    SFTPInterface(SFTPInterface&& other) = delete;
    ~SFTPInterface();

    SFTPInterface&operator=(const SFTPInterface& other) = delete;
    SFTPInterface&operator=(SFTPInterface&& other) = delete;

    void open_connection();
    void close_connection();
    void changeDir(string path);
    void upload(string, string);
    void download(string);
};

#endif // SFTPINTERFACE_H
