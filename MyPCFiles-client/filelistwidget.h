//
// Created by jahongir on 28/10/18.
//

#ifndef MYPCFILES_FILESLISTWIDGET_H
#define MYPCFILES_FILESLISTWIDGET_H

#include <QListWidget>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <libssh/sftp.h>

class FileListWidget: public QListWidget {
    Q_OBJECT

public:
    FileListWidget(QWidget* parent = nullptr);
    ~FileListWidget();

    void add(QString str, bool is_dir = false);
};

#endif //MYPCFILES_FILESLISTWIDGET_H
