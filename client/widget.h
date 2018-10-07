#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QLineEdit>
#include <QPushButton>
#include <string>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();

private:
    Ui::Widget *ui;
    QTcpSocket *client;

    void sendText();
};

#endif // WIDGET_H
