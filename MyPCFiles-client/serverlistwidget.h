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
#include <QVariant>

using std::unique_ptr;
using std::shared_ptr;

class ServerListWidget: public QListWidget{

    Q_OBJECT
public:
    ServerListWidget(QWidget* parent = nullptr);
    ServerListWidget(const ServerListWidget&) = delete;
    ServerListWidget(ServerListWidget&&) = delete;
    ~ServerListWidget() = default;

    ServerListWidget&operator=(const ServerListWidget&) = delete;
    ServerListWidget&operator=(ServerListWidget&&) = delete;

    void add_new(unique_ptr<Server> server);
private:
    ServerList serverlist;

    void add(shared_ptr<Server> server);
private slots:
    void serverConnectButtonOnClick();
};
#endif // SERVERLISTWIDGET_H
