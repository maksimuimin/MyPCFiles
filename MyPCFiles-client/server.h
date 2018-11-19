#ifndef SERVER_H
#define SERVER_H

#include <QString>
#include <libssh/sftp.h>

class Server {

public:
    QString alias;

    Server(): username(""), host(""), port(0), alias("New server") {}
    Server(QString _username, QString _host, unsigned int _port, QString _alias):
        username(_username), host(_host), port(_port), alias(_alias) {}
    Server(const Server& other) = delete;
    Server(Server&& other) = delete;
    ~Server();

    Server&operator=(const Server& other) = delete;
    Server&operator=(Server&& other) = delete;

    void disconnect();
    void connect();
private:

    QString username;
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
