#include "mainwindow.h"

MainWindow::MainWindow(): QWidget(){

    this->setWindowTitle("MyPCFiles");
    this->setAutoFillBackground(true);

    navbar = new NavbarWidget(this);

    logo = new QLabel(this);
    logo->setPixmap(QPixmap(":img/logo.png"));//TODO

    QFont font;
    font.setPixelSize(16);

    serverList = new ServerListWidget(this);
    serverList->setFont(font);
    serverList->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    serverList->setAlternatingRowColors(true);
    serverList->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);

    addServerBtn = new QPushButton("Add new server", this);
    font.setPixelSize(20);
    addServerBtn->setFont(font);
    connect(addServerBtn, SIGNAL(clicked()), this, SLOT(addServerBtnOnClick()));

    mainLayout = new QVBoxLayout(this);
    mainLayout->setMenuBar(navbar);
    mainLayout->addWidget(logo, 0, Qt::AlignmentFlag::AlignHCenter);
    mainLayout->addWidget(serverList);
    mainLayout->addWidget(addServerBtn);
}

MainWindow::~MainWindow(){
    delete navbar;
    delete logo;
    delete serverList;
    delete addServerBtn;
    delete mainLayout;
}

void MainWindow::addServerBtnOnClick(){
    ServerInputDialog dialog;
    dialog.exec();
    if(dialog.result() == dialog.Accepted){
        unique_ptr<Server> server (new Server(dialog.userName->text(),
                                              dialog.password->text(),
                                              dialog.hostName->text(),
                                              dialog.port->text().toInt(),
                                              dialog.serverName->text()));
        serverList->add_new(std::move(server));
        BOOST_LOG_TRIVIAL(info) << "Added new server: " << dialog.hostName;
    }
}

MainWindow::ServerInputDialog::ServerInputDialog(QWidget* parent) : QDialog(parent) {
    this->setModal(true);
    this->setWindowTitle("MyPCFiles - Editing server");

    serverName->setPlaceholderText("My new Server");
    hostName->setPlaceholderText("www.myhost.com  or  192.168.0.1");//Set input mask
    port->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
    port->setPlaceholderText("22");
    port->setValidator(new QIntValidator(0,65535,port));
    userName->setPlaceholderText("User");
    password->setEchoMode(QLineEdit::EchoMode::Password);

    connect(OKButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(CancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    inputLayout->addRow(tr("Server name:"),serverName);
    inputLayout->addRow(tr("Host or IP:"),hostName);
    inputLayout->addRow(tr("Port:"),port);
    inputLayout->addRow(tr("User name:"),userName);
    inputLayout->addRow(tr("Password:"), password);
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(OKButton);
    buttonsLayout->addWidget(CancelButton);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonsLayout);
    this->setLayout(mainLayout);
}

MainWindow::ServerInputDialog::~ServerInputDialog(){
    delete OKButton;
    delete CancelButton;
    delete serverName;
    delete hostName;
    delete port;
    delete userName;
    delete password;
    delete inputLayout;
}
