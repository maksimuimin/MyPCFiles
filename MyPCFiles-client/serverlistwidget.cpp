#include "serverlistwidget.h"

ServerListWidget::ServerListWidget(QWidget* parent){
    //TODO write constructor
    //Необходимо создать виджет, предоставляющий пользователю интерфейс для работы со списком серверов
    //Необходимые функции:
    //1)Удалить сервер
    //2)Изменить настройки сервера
}

ServerListWidget::~ServerListWidget(){
    //TODO write destructor
    //Необходимо освободить всю динамическую память
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
