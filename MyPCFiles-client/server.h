#ifndef SERVER_H
#define SERVER_H

#include <libssh/libssh.h>
#include <libssh/sftp.h>
#include <string>
#include <cstdarg>

#include <QString>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>

using std::string;

class Server {

public:
    Server(): alias("New server"), username(""), password(""), host(""), port(0) {}
    Server(QString _username, QString _password, QString _host, unsigned int _port, QString _alias):
        alias(_alias), username(_username), password(_password), host(_host), port(_port) {}
    Server(const Server& other) = delete;
    Server(Server&& other) = delete;
    ~Server();

    Server& operator=(const Server&) = delete;
    Server& operator=(Server&&) = delete;

    void connect();
    void disconnect();
    void showErrorDialog(QString message);
    QString strConcat(int n_args, ...);

    sftp_session getSftp() { return sftp; }
    ssh_session getSsh(){ return ssh; }
    QString getAlias(){ return alias; }

private:
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

#endif // SERVER_H
