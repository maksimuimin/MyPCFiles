//
// Created by jahongir on 28/10/18.
//

#include "filelistwidget.h"

FileListWidget::FileListWidget(QWidget* parent) {
    // TODO default constructor
    //В конструкторе необходимо создать графический интерфейс, через который пользователь будет взаимодействовать со списком файлов в некоторой директоррии
    //Интерфейс должен поддерживать следующие функции
    //1)Сменить директорию
    //2)Загрузить файл на сервер
    //3)Скачать файл с сервера
}

FileListWidget::~FileListWidget() {
    // TODO destructor
    //В деструкторе необходимо освободить всю память, запрошенную у системы в конструкторе
}

void FileListWidget::add(sftp_attributes attrs) {
    // TODO add file to file-list
    //Функция добавления файла в список
    //Список входных оргументов может быть изменён в процессе разработки,
    //но обязательно должен быть синхронизирован с методами changeDir и upload классов SFTPInterface и SFTPInterfaceWidget
}
