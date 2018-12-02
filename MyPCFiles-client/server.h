#ifndef SERVER_H
#define SERVER_H

#include <QString>
#include <libssh/sftp.h>

class Server {

public:
    QString alias;

    Server(): alias("New server"), username(""), password(""), host(""), port(0) {}
    Server(QString _username, QString _password, QString _host, unsigned int _port, QString _alias):
        alias(_alias), username(_username), password(_password), host(_host), port(_port) {}
    Server(const Server& other) = delete;
    Server(Server&& other) = delete;
    ~Server();

    Server&operator=(const Server& other) = delete;
    Server&operator=(Server&& other) = delete;

    void disconnect();
    void connect();
private:

    QString username;
    QString password;
    QString host;
    unsigned int port;
    ssh_session ssh;
    ssh_key publicKey;
    sftp_session sftp;

    void verifyServer();
    void auth();
    void generateKeys();
    void showErrorDialog();
};

#endif // SERVER_H
