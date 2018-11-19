#include "serverlistwidget.h"

ServerListWidget::ServerListWidget(std::vector<Server> list, QWidget* parent){
    //TODO write constructor
    //Необходимо создать виджет, предоставляющий пользователю интерфейс для работы со списком серверов
    //Необходимые функции:
    //1)Удалить сервер
    //2)Изменить настройки сервера
    std::for_each(list.begin(), list.end(), [this](const Server& s){
       this->add(s);
    });
}

ServerListWidget::~ServerListWidget(){
    //TODO write destructor
    //Необходимо освободить всю динамическую память
}

void ServerListWidget::add(const Server server) {
    QListWidgetItem item;
    item.setText(server.alias);
    //TODO написать класс - наследник QListWidgetItem
    this->addItem()
}

void ServerListWidget::change(const size_t pos){
    //TODO add server to server list
    //Слот, изменяющий настройки сервера
    //Для этого необходимо создать диалог, запрашивающий у пользователя новые настройки
    //Затем нужно вызвать функцию change() класса serverList
}

void ServerListWidget::remove(const size_t pos){
    //TODO remove server from server list
    //Слот, удаляющий сервер из списка
    //Для этого необходимо создать диалог, запрашивающий у пользователя подтверждение
    //Затем нужно вызвать функцию remove() класса serverList
}
