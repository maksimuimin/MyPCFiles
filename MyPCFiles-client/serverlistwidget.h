#ifndef SERVERLISTWIDGET_H
#define SERVERLISTWIDGET_H

#include <QString>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include "serverlist.h"
#include <algorithm>
#include <memory>

using std::unique_ptr;
using std::shared_ptr;

class ServerListWidget: public QListWidget{

    Q_OBJECT
public:
    ServerListWidget(QWidget* parent = nullptr);
    ServerListWidget(const ServerListWidget& other) = delete;
    ServerListWidget(ServerListWidget&& other) = delete;
    ~ServerListWidget() = default;

    ServerListWidget&operator=(const ServerListWidget& other) = delete;
    ServerListWidget&operator=(ServerListWidget&& other) = delete;

    void add_new(unique_ptr<Server> server);
private:
    ServerList serverlist;

    void add(shared_ptr<Server> server);
};
#endif // SERVERLISTWIDGET_H
