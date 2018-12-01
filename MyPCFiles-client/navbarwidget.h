#ifndef NAVBARWIDGET_H
#define NAVBARWIDGET_H

#include <QPushButton>
#include <QLabel>
#include <QMenuBar>

class NavbarWidget: public QMenuBar {
    Q_OBJECT

private:
    QLabel logo;
public:
    NavbarWidget(QWidget* parent = nullptr);
    NavbarWidget(const NavbarWidget& other) = delete;
    NavbarWidget(NavbarWidget&& other) = delete;
    ~NavbarWidget();

    NavbarWidget&operator=(const NavbarWidget& other) = delete;
    NavbarWidget&operator=(NavbarWidget& other) = delete;
};

#endif
