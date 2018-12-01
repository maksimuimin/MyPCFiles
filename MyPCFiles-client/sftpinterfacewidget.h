//
// Created by jahongir on 28/10/18.
//

#ifndef MYPCFILES_SFTPINTERFACEWIDGET_H
#define MYPCFILES_SFTPINTERFACEWIDGET_H

#include <QWidget>
#include "filelistwidget.h"
#include "sftpinterface.h"

class SFTPInterfaceWidget: QWidget {

    Q_OBJECT

private:
    FileListWidget filesList;
    SFTPInterface interface;

public:
    SFTPInterfaceWidget(QWidget* parent = nullptr, SFTPInterface* _interface = nullptr);
    SFTPInterfaceWidget(const SFTPInterfaceWidget& other) = delete;
    SFTPInterfaceWidget(SFTPInterfaceWidget&& other) = delete;
    ~SFTPInterfaceWidget();

    SFTPInterfaceWidget&operator=(const SFTPInterfaceWidget& other) = delete;
    SFTPInterfaceWidget&operator=(SFTPInterfaceWidget&& other) = delete;

public slots:
    void open_connection();
    void close_connection();
    void changeDir();
    void upload();
    void download();

};

#endif //MYPCFILES_SFTPINTERFACEWIDGET_H
