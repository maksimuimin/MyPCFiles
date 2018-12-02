#include "serverlistwidget.h"

ServerListWidget::ServerListWidget(QWidget* parent) : QListWidget (parent){
    //std::for_each(serverlist.begin(), serverlist.end(), [this](Server* s){
       //this->add(unique_ptr<Server>(s));
    //});
    this->add_new(unique_ptr<Server>(new Server()));
    this->add_new(unique_ptr<Server>(new Server()));
    this->add_new(unique_ptr<Server>(new Server()));
}

void ServerListWidget::add_new(unique_ptr<Server> server){
    //TODO put in server list
    shared_ptr<Server> shared_server = shared_ptr<Server>(std::move(server));
    serverlist.add(shared_server);
    this->add(shared_server);
}

void ServerListWidget::add(const shared_ptr<Server> server) {
    QListWidgetItem* item = new QListWidgetItem(this);
    QWidget* widget = new QWidget;

    QLabel* title = new QLabel(server->getAlias(), widget);
    QPushButton* connectBtn = new QPushButton(QIcon(":img/connect.png"),"",widget);
    QPushButton* settingsBtn = new QPushButton(QIcon(":img/settings.png"),"",widget);
    QPushButton* deleteBtn = new QPushButton(QIcon(":img/delete.png"),"",widget);
    QHBoxLayout* mainLayout = new QHBoxLayout(widget);
    mainLayout->addWidget(title);
    mainLayout->addStretch();
    mainLayout->addWidget(connectBtn);
    mainLayout->addWidget(settingsBtn);
    mainLayout->addWidget(deleteBtn);

    item->setSizeHint(widget->sizeHint());
    this->setItemWidget(item, widget);
}
