#ifndef SFTPINTERFACE_H
#define SFTPINTERFACE_H

#include <list>
#include "server.h"

using std::list;

class SFTPInterface {
private:
    Server* server;
    list<sftp_file> files;
    string nameDir;
public:
    SFTPInterface(Server* _server = nullptr): server(_server), files(nullptr) {}//TODO заменить указатель на умный из stl
    SFTPInterface(const SFTPInterface& other) = delete;
    SFTPInterface(SFTPInterface&& other) = delete;
    ~SFTPInterface();

    SFTPInterface&operator=(const SFTPInterface& other) = delete;
    SFTPInterface&operator=(SFTPInterface&& other) = delete;

    void open_connection();
    void close_connection();
    void changeDir();
    void upload(string, string);
    void download(string);
};

#endif // SFTPINTERFACE_H
