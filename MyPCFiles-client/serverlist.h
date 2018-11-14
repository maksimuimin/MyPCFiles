#ifndef SERVERLIST_H
#define SERVERLIST_H

#include <QVector>
#include "server.h"

class ServerList{

private:
    QVector<Server> list;

    void add(QString _host, unsigned int _port, QString _username);
    void remove(size_t pos);
    void change(size_t pos, QString _host = "", unsigned int _port = 0, QString _username = "");

public:
    ServerList();
    ServerList(const ServerList& other) = delete;
    ServerList(ServerList&& other) = delete;
    ~ServerList();

    ServerList&operator=(const ServerList& other) = delete;
    ServerList&operator=(ServerList&& other) = delete;
};

#endif // SERVERLIST_H
