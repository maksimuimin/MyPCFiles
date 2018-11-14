#ifndef SERVERLISTWIDGET_H
#define SERVERLISTWIDGET_H

#include <QString>
#include <QListWidget>
#include "serverlist.h"

class ServerListWidget: public QListWidget{

    Q_OBJECT

public:
    ServerListWidget(QWidget* parent = nullptr);
    ServerListWidget(const ServerListWidget& other) = delete;
    ServerListWidget(ServerListWidget&& other) = delete;
    ~ServerListWidget();

    ServerListWidget&operator=(const ServerListWidget& other) = delete;
    ServerListWidget&operator=(ServerListWidget&& other) = delete;

public slots:
    void change(const size_t pos);
    void remove(const size_t pos);
};
#endif // SERVERLISTWIDGET_H
