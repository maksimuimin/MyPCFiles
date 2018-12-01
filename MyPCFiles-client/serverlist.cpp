#include "serverlist.h"


ServerList::ServerList() {
    //Необходимо и сформировать список серверов из БД
}

ServerList::~ServerList() {
    //Необходимо сохранить списовк серверов в БД и освободить всю запрошенную у ОС память
}

void ServerList::add(QString _host, unsigned int _port, QString _username) {
    //Необходимо создать новый сревер и добавить его в список
    //Входные данные определяются данными, необходимыми для вызова конструктора класса Server
    //Данные на вход получаются из функции add класса ServerListWidget и должны быть синхронизированы
}

void ServerList::remove(size_t pos) {
    //Необходимо удалить сервер из списка и из БД
}

void ServerList::change(size_t pos, QString _host, unsigned int _port, QString _username) {
    //Необходимо изменить настройки сервера
}
