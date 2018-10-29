//
// Created by jahongir on 28/10/18.
//

#ifndef MYPCFILES_FILESLISTWIDGET_H
#define MYPCFILES_FILESLISTWIDGET_H

#include <QWidget>
#include "fake_libssh.h"

class FilesListWidget {
    Q_OBJECT

public:
    FilesListWidget(QWidget* parent = nullptr);
    ~FilesListWidget();

    void add(sftp_attributes attrs);
};

#endif //MYPCFILES_FILESLISTWIDGET_H
