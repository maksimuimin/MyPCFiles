//
// Created by jahongir on 28/10/18.
//

#ifndef MYPCFILES_SFTPINTERFACEWIDGET_H
#define MYPCFILES_SFTPINTERFACEWIDGET_H

#include "filelistwidget.h"
#include <QList>
#include <QWidget>
#include "server.h"
#include "fake_libssh.h"

class SFTPInterfaceWidget: QWidget {

    Q_OBJECT

private:
    FileListWidget filesList;
    Server* server;

public:
    QList<sftp_file> files;
    SFTPInterfaceWidget(QWidget* parent = nullptr, Server* _server = nullptr);
    SFTPInterfaceWidget(const SFTPInterfaceWidget& other) = delete;
    SFTPInterfaceWidget(SFTPInterfaceWidget&& other) = delete;
    ~SFTPInterfaceWidget();

    SFTPInterfaceWidget&operator=(const SFTPInterfaceWidget& other) = delete;
    SFTPInterfaceWidget&operator=(SFTPInterfaceWidget&& other) = delete;

    void open(const char*);
    void close();
    void changeDir();
    void upload();
    void download();

};

#endif //MYPCFILES_SFTPINTERFACEWIDGET_H
