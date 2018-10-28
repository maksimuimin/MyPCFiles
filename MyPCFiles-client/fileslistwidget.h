//
// Created by jahongir on 28/10/18.
//

#ifndef MYPCFILES_FILESLISTWIDGET_H
#define MYPCFILES_FILESLISTWIDGET_H

#include <QWidget>

class FilesListWidget {
public:
    FilesListWidget(QWidget* parent);
    ~FilesListWidget();

    void add(sftp_attributes attrs);
};

#endif //MYPCFILES_FILESLISTWIDGET_H
