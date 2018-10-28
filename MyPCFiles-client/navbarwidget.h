#ifndef NAVBARWIDGET_H
#define NAVBARWIDGET_H

#include <QPushButton>
#include <QLabel>

class NavbarWidget {
private:
    QPushButton menuBtn;
    QLabel logo;
public:
    NavbarWidget(QWidget* parent = nullptr);
    NavbarWidget(const NavbarWidget& other) = delete;
    NavbarWidget(NavbarWidget&& other) = delete;
    ~NavbarWidget();

    NavbarWidget&operator=(const NavbarWidget& other) = delete;
    NavbarWidget&operator=(NavbarWidget& other) = delete;
public slots:
    void menuBtnOnClick();
};
#endif // NAVBARWIDGET_H
