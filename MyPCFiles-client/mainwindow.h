#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "navbarwidget.h"
#include "serverlistwidget.h"

class MainWindow : public QMainWindow{
    Q_OBJECT

private:
    QLabel logo;
    ServerListWidget serverList;
    NavbarWidget navbar;
    QPushButton addServerBtn;

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
};

#endif // MAINWINDOW_H
