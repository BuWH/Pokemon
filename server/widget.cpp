#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget) {
    ui->setupUi(this);
    server = new QTcpServer();
    server->listen(QHostAddress::Any, 6666);
    qDebug() << "Started Listening...";
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

Widget::~Widget() {
    delete ui;
}

void Widget::acceptConnection() {
    clientConnection = server->nextPendingConnection();
    qDebug() << "new connection:" << clientConnection->peerAddress().toString() << clientConnection->peerPort();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void Widget::readClient() {
    QString str = clientConnection->readAll();
    //QDateTime local = QDateTime::currentDateTime();
    //QString localTime = local.toString("yyyy-MM-dd:hh:mm:ss");
    qDebug() << "get : " << str;
    this->processRequest(str);
}

void Widget::processRequest(QString str) {
    QString temp = str.section(',', 0, 0);
    if (temp == "login") {
        QString account = str.section(',', 1, 1);
        QString password = str.section(',', 2, 2);
        this->login(account, password);
    }
    if (temp == "signup") {
        QString account = str.section(',', 1, 1);
        QString password = str.section(',', 2, 2);
        this->signup(account, password);
    }
    if (temp == "logout") {
        qDebug() << 'logout';
    }
}

void Widget::signup(QString account, QString password) {
    QFile database("accounts.txt");
    if (!database.open(QFile::WriteOnly | QFile::Text | QFile::Append)) {
        qDebug() << "database open error";
        return;
    }
    if (this->accountExist(account) == FALSE) {
        QTextStream data(&database);
        data << account << "," << password << "\n";
        qDebug() << "signup: " << account << " " << password;
        database.close();
        return;
    } else if (this->accountExist(account) == ERROR) {
        clientConnection->write("server error");
        clientConnection->waitForBytesWritten();
    } else {
        qDebug() << "account exists";
        clientConnection->write("signup denied");
        clientConnection->waitForBytesWritten();
    }
}

void Widget::login(QString account, QString password) {
    QFile database("accounts.txt");
    if (!database.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "send: database open error";
        clientConnection->write("server error");
        clientConnection->waitForBytesWritten();
    }
    QTextStream data(&database);
    QString temp, temp1, temp2;
    while (!data.atEnd()) {
        temp = data.readLine();
        temp1 = temp.trimmed().section(',', 0, 0);
        temp2 = temp.trimmed().section(',', 1, 1);
        if (temp1 == account && temp2 == password) {
            qDebug() << "send: login permitted";
            clientConnection->write("login permitted");
            clientConnection->waitForBytesWritten();
            database.close();
            return;
        }
    }
    qDebug() << "send: login denied";
    clientConnection->write("login denied");
    clientConnection->waitForBytesWritten();
    database.close();
}

int Widget::accountExist(QString str) {
    QFile database("accounts.txt");
    if (!database.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "database open error";
        return ERROR;
    }
    QTextStream data(&database);
    QString temp;
    while (!data.atEnd()) {
        temp = data.readLine();
        temp = temp.trimmed().section(',', 0, 0);
        if (temp == str)
            return TRUE;
    }
    database.close();
    return FALSE;
}