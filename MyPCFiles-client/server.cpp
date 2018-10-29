#include <server.h>

Server::Server(QString _username, QString _host, unsigned int _port){
    //TODO write constructor
}

Server::Server(Server&& other){
    //TODO write move constructor
}

Server::~Server(){
    //TODO write destructor
}

Server& Server::operator=(Server&& other){
    //TODO write move operator
}

void Server::disconnect(){
    //TODO cancel sftp/ssh connection
}

void Server::connect(){
    //TODO open sftp/ssh connection
}

void Server::verifyServer(){
    //TODO check server eventide
}

void Server::auth(){
    //TODO provide autitification on the server
}

void Server::generateKeys(){
    //TODO generate Keys
}

void Server::showErrorDialog(){
    //TODO dialog of error
}
