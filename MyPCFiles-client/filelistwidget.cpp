//
// Created by jahongir on 28/10/18.
//

#include "filelistwidget.h"

FileListWidget::FileListWidget(QWidget* parent): QListWidget(parent) {
    // TODO default constructor
    //В конструкторе необходимо создать графический интерфейс, через который пользователь будет взаимодействовать со списком файлов в некоторой директоррии
    //Интерфейс должен поддерживать следующие функции
    //1)Сменить директорию
    //2)Загрузить файл на сервер
    //3)Скачать файл с сервера
    this->add("File 1");
    this->add("File 2");
    this->add("Dir1",true);
}

FileListWidget::~FileListWidget() {
    // TODO destructor
    //В деструкторе необходимо освободить всю память, запрошенную у системы в конструкторе
}

void FileListWidget::add(QString str, bool is_dir) {
    // TODO add file to file-list
    //Функция добавления файла в список
    //Список входных оргументов может быть изменён в процессе разработки,
    //но обязательно должен быть синхронизирован с методами changeDir и upload классов SFTPInterface и SFTPInterfaceWidge
    QListWidgetItem* item = new QListWidgetItem(this);
    QWidget* widget = new QWidget;

    QLabel* icon = new QLabel(widget);
    icon->setPixmap(is_dir ? QPixmap(":img/folder.png") : QPixmap(":img/file.png"));
    QLabel* title = new QLabel(str, widget);
    QHBoxLayout* mainLayout = new QHBoxLayout(widget);
    mainLayout->addWidget(icon);
    mainLayout->addWidget(title);
    mainLayout->addStretch();
    if(is_dir){
        QPushButton* openBtn = new QPushButton(QIcon(":img/open.png"),"",widget);
        mainLayout->addWidget(openBtn);
    }
    QPushButton* downloadBtn = new QPushButton(QIcon(":img/download.png"),"",widget);
    mainLayout->addWidget(downloadBtn);
    item->setSizeHint(widget->sizeHint());
    this->setItemWidget(item, widget);
}
