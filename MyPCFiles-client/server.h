#ifndef SERVER_H
#define SERVER_H

#include <libssh/libssh.h>
#include <libssh/sftp.h>

#include <string>
#include <cstdarg>
#include <memory>
#include <iostream>

#include <QString>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>
#include <QErrorMessage>

using std::string;

class Server {

public:
    Server(): alias("New server"), username(""), password(""), host(""), port(0) {}
    Server(QString _username, QString _password, QString _host, unsigned int _port, QString _alias):
        alias(_alias), username(_username), password(_password), host(_host), port(_port) {}
    Server(const Server& other) = delete;
    Server(Server&& other) = delete;
    ~Server() = default;

    Server& operator=(const Server&) = delete;
    Server& operator=(Server&&) = delete;

    void connect();
    void disconnect();

    sftp_session getSftp() { return sftp; }
    ssh_session getSsh(){ return ssh; }
    QString getAlias(){ return alias; }
    bool is_connected() {return connected; }

    static void SERVER_ERROR(string message);
    static void SERVER_ERROR(int n_args, ...);
private:
    bool connected = false;
    QString alias;
    QString username;
    QString password;
    QString host;
    unsigned int port;
    ssh_session ssh;
    ssh_key publicKey;
    sftp_session sftp;

    bool verifyServer();
    bool auth();
    bool generateKeys();
};

Q_DECLARE_METATYPE(Server*);

#endif // SERVER_H
