#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QIntValidator>
#include <memory>
#include "navbarwidget.h"
#include "serverlistwidget.h"

class MainWindow : public QWidget{
    Q_OBJECT

public:
    MainWindow();
    MainWindow(const MainWindow& other) = delete;
    MainWindow(MainWindow&& other) = delete;
    ~MainWindow();

    MainWindow&operator=(const MainWindow& other) = delete;
    MainWindow&operator=(MainWindow&& other) = delete;

public slots:
    void addServerBtnOnClick();
    //TODO createNewConnection();

private:
    NavbarWidget* navbar;
    QLabel* logo;
    ServerListWidget* serverList;
    QPushButton* addServerBtn;
    QVBoxLayout* mainLayout;

    struct ServerInputDialog : QDialog {
        ServerInputDialog(QWidget* parent = nullptr);
        ServerInputDialog(const ServerInputDialog& other) = delete;
        ServerInputDialog(ServerInputDialog&& other) = delete;
        ~ServerInputDialog();

        ServerInputDialog&operator=(const ServerInputDialog& other) = delete;
        ServerInputDialog&operator=(ServerInputDialog&& other) = delete;

        QPushButton* OKButton = new QPushButton("OK", this);
        QPushButton* CancelButton = new QPushButton("Cancel", this);
        QHBoxLayout* buttonsLayout = new QHBoxLayout();
        QLineEdit* serverName = new QLineEdit(this);
        QLineEdit* hostName = new QLineEdit(this);
        QLineEdit* port = new QLineEdit(this);
        QLineEdit* userName = new QLineEdit(this);
        QLineEdit* password = new QLineEdit(this);
        QFormLayout* inputLayout = new QFormLayout();
        QVBoxLayout* mainLayout = new QVBoxLayout(this);
    };
};
#endif // MAINWINDOW_H
