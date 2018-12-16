//
// Created by jahongir on 28/10/18.
//

#ifndef MYPCFILES_SFTPINTERFACEWIDGET_H
#define MYPCFILES_SFTPINTERFACEWIDGET_H

#include <QDialog>
#include "filelistwidget.h"
#include "sftpinterface.h"
#include <QVBoxLayout>
#include <QPushButton>

using std::shared_ptr;

class SFTPInterfaceWidget: public QDialog {

    Q_OBJECT

private:
    FileListWidget* filesList;
    QPushButton* uploadBtn;
    QVBoxLayout* mainLayout;
    SFTPInterface interface;

public:
    SFTPInterfaceWidget(QWidget* parent = nullptr, shared_ptr<Server> server = nullptr);
    SFTPInterfaceWidget(const SFTPInterfaceWidget& other) = delete;
    SFTPInterfaceWidget(SFTPInterfaceWidget&& other) = delete;
    ~SFTPInterfaceWidget();

    SFTPInterfaceWidget&operator=(const SFTPInterfaceWidget& other) = delete;
    SFTPInterfaceWidget&operator=(SFTPInterfaceWidget&& other) = delete;

public slots:
    void changeDir();
    void upload();
    void download();

};

#endif //MYPCFILES_SFTPINTERFACEWIDGET_H
