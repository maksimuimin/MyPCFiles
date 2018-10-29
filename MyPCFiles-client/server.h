#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>

class Server {
public:
    Server(QString _username, QString _host, unsigned int _port);
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
