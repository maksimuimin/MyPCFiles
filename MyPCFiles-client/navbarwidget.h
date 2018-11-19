#ifndef NAVBARWIDGET_H
#define NAVBARWIDGET_H

#include <QPushButton>
#include <QLabel>
#include <QMenuBar>
#include <QMessageBox>

class NavbarWidget: public QMenuBar {
    Q_OBJECT
public:
    NavbarWidget(QWidget* parent = nullptr);
    NavbarWidget(const NavbarWidget& other) = delete;
    NavbarWidget(NavbarWidget&& other) = delete;
    ~NavbarWidget() = default;

    NavbarWidget&operator=(const NavbarWidget& other) = delete;
    NavbarWidget&operator=(NavbarWidget& other) = delete;
private slots:
    void settings_menu_on_click();
};

#endif
