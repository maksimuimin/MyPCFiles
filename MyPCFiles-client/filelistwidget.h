//
// Created by jahongir on 28/10/18.
//

#ifndef MYPCFILES_FILESLISTWIDGET_H
#define MYPCFILES_FILESLISTWIDGET_H

#include <QListWidget>
#include <QWidget>
#include "fake_libssh.h"

class FileListWidget: public QListWidget {
    Q_OBJECT

public:
    FileListWidget(QWidget* parent = nullptr);
    ~FileListWidget();

    void add(sftp_attributes attrs);
};

#endif //MYPCFILES_FILESLISTWIDGET_H
