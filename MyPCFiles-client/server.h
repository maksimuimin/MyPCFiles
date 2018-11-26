#ifndef SERVER_H
#define SERVER_H

#include <QString>
#include <libssh/sftp.h>
#include <string>

using std::string;

class Server {

public:
    Server(): username(""), host(""), port(0) {}
    Server(string _username, string _host, unsigned int _port):
        username(_username), host(_host), port(_port) {}
    Server(const Server& other) = delete;
    Server(Server&& other) = delete;
    ~Server();

    Server& operator=(const Server&) = delete;
    Server& operator=(Server&&) = delete;

    void disconnect();
    void connect();
private:

    string username;
    string host;
    unsigned int port;
    ssh_session ssh;
    ssh_key publicKey;
    sftp_session sftp;

    bool verifyServer();
    bool auth();
    bool generateKeys();
    void showErrorDialog(QString message);
    QString strConcat(int n_args, ...);
};

#endif // SERVER_H
