//
// Created by 温和 on 2018/11/17.
//

#include "mysocket.h"

#include <qthread.h>
#include <qlist.h>
#include "myserver.h"

TcpSocket::TcpSocket(int sock, QTcpSocket *parent) : QTcpSocket(parent) {
    this->setSocketDescriptor(sock);
    login_db = QSqlDatabase::addDatabase("QSQLITE", QString::number(sock));
    login_db.setDatabaseName("accounts.db");
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(SocketErr(QAbstractSocket::SocketError)));
}

TcpSocket::~TcpSocket()
{
    login_db.close();
}

void TcpSocket::ReadAndParseData() {
    TcpSocket *socket = (TcpSocket *) sender();
    QString recvStr = socket->readAll();
    qDebug() << "get: " + recvStr;
    processRequest(recvStr);
    m_recvDataStr += recvStr;
    // 对数据的处理
}

void TcpSocket::SocketErr(QAbstractSocket::SocketError socketError) {
    TcpSocket *socket = (TcpSocket *) sender();
    //WLog(LOG_ERR, "socket[%d] ip[%s] port[%d] err[%s]", socket->socketDescriptor(),
    //   socket->peerAddress().toString().toLocal8Bit().data(),socket->peerPort(),socket->errorString().toLocal8Bit().data());
}

void TcpSocket::processRequest(QString str) {
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

void TcpSocket::signup(QString account, QString password) {
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
        this->write("server error");
        this->waitForBytesWritten();
    } else {
        qDebug() << "account exists";
        this->write("signup denied");
        this->waitForBytesWritten();
    }
}

void TcpSocket::login(QString account, QString password) {
    /*
    QFile database("accounts.txt");
    if (!database.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "send: database open error";
        this->write("server error");
        this->waitForBytesWritten();
        return;
    }
    QTextStream data(&database);
    QString temp, temp1, temp2;
    while (!data.atEnd()) {
        temp = data.readLine();
        temp1 = temp.trimmed().section(',', 0, 0);
        temp2 = temp.trimmed().section(',', 1, 1);
        if (temp1 == account && temp2 == password) {
            qDebug() << "send: login permitted";
            this->write("login permitted");
            this->waitForBytesWritten();
            database.close();
            return;
        }
    }
    qDebug() << "send: login denied";
    this->write("login denied");
    this->waitForBytesWritten();
    database.close();
    */
    if (!login_db.open()) {
        qDebug() << "database open error";
    } else {
        QSqlQuery qry(login_db);
        /*
        qry.prepare( "DROP TABLE account" );
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
            qDebug() << "Table deleted!";
        */
        //创建table
        qry.prepare(
                "CREATE TABLE IF NOT EXISTS account (id INTEGER UNIQUE PRIMARY KEY, name VARCHAR(30) UNIQUE, password VARCHAR(30), status INT default 0)");
        if (!qry.exec())
            qDebug() << qry.lastError();
        else
            qDebug() << "Table created!";

        qry.prepare("SELECT name,password,status FROM account WHERE name = ?");
        qry.bindValue(0, "\'" + account + "\'");
        if (!qry.exec()) {
            qDebug() << qry.lastError();
        } else {
            if (qry.next()) {
                QString name = qry.value(0).toString();
                QString db_password = qry.value(1).toString();
                bool status = qry.value(2).toBool();
                qDebug() << name << db_password;
            } else {
                qDebug() << "no data";
            }

        }
    }
}

int TcpSocket::accountExist(QString str) {
    /*
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
     */
    if (!login_db.open()) {
        qDebug() << "database open error";
    } else {
        QSqlQuery qry(login_db);

        qry.prepare("SELECT name FROM account WHERE name = ?");
        qry.bindValue(0, "\'" + str + "\'");
        if (!qry.exec()) {
            qDebug() << qry.lastError();
        } else {
            QString name = qry.value(0).toString();
            qDebug() << name;
        }
    }
}