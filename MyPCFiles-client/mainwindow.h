#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include "navbarwidget.h"
#include "serverlistwidget.h"

class MainWindow : public QWidget{
    Q_OBJECT

private:
    NavbarWidget* navbar;
    QLabel* logo;
    ServerListWidget* serverList;
    QPushButton* addServerBtn;
    QVBoxLayout* mainLayout;

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
