#ifndef SERVER_H
#define SERVER_H

#include <QString>
#include "fake_libssh.h"

class Server {

public:
    Server(QString _username = "user", QString _host = "localhost", unsigned int _port = 22);
    Server(const Server& other) = delete;
    Server(Server&& other);
    ~Server();

    Server&operator=(const Server& other) = delete;
    Server&operator=(Server&& other);

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
