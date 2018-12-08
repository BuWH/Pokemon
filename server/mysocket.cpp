//
// Created by 温和 on 2018/11/17.
//

#include "mysocket.h"

#include <qthread.h>
#include <qlist.h>
#include "myserver.h"

TcpSocket::TcpSocket(int sock, QTcpSocket *parent) : QTcpSocket(parent) {
    this->setSocketDescriptor(sock);
    account_db = QSqlDatabase::addDatabase("QSQLITE", QString::number(sock));
    account_db.setDatabaseName("accounts.db");
    creature_db = QSqlDatabase::addDatabase("QSQLITE", QString::number(sock) + "creature");
    creature_db.setDatabaseName("creatures.db");
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(SocketErr(QAbstractSocket::SocketError)));
}

TcpSocket::~TcpSocket() {
    account_db.close();
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
        QString account = str.section(',', 1, 1);
        this->logout(account);
    }
    if (temp == "updateuser") {
        int id = str.section(',', 1, 1).toInt();
        QString account = str.section(',', 2, 2);
        int winfights = str.section(',', 3, 3).toInt();
        int totalfights = str.section(',', 4, 4).toInt();
        int num = str.section(',', 5, 5).toInt();
        updateUserData(id, account, winfights, totalfights, num);
        for (int i = 0; i < num; ++i) {
            updateCreature(str.section(',', 6 + i * 11, 16 + i * 11));
        }
    }
}

void TcpSocket::signup(QString account, QString password) {

    if (!account_db.open()) {
        qDebug() << "database open error";
    } else {
        QSqlQuery qry(account_db);
        ///*
        qry.prepare( "DROP TABLE account" );
        if( !qry.exec() )
            qDebug() << qry.lastError();
        //*/
        //创建table
        qry.prepare("CREATE TABLE IF NOT EXISTS account (id INTEGER UNIQUE PRIMARY KEY, name VARCHAR(30) UNIQUE"
                    ", password VARCHAR(30), status INT DEFAULT 0, winfights INT DEFAULT 0, totalfights INT DEFAULT 0, num INT DEFAULT 0)");
        if (!qry.exec())
            qDebug() << qry.lastError();
        qry.prepare("SELECT name FROM account WHERE name = ?");
        qry.bindValue(0, "\'" + account + "\'");
        if (!qry.exec()) {
            qDebug() << qry.lastError();
        } else {
            if (qry.next()) {
                QString name = qry.value(0).toString();
                qDebug() << "account: " << name << "exists!";
            } else {
                qry.prepare("INSERT INTO account (id, name, password) VALUES (NULL, ? , ?)");
                qry.bindValue(0, "\'" + account + "\'");
                qry.bindValue(1, "\'" + password + "\'");
                if (!qry.exec()) {
                    qDebug() << "sign up error: " << account + " " + password;
                    this->write("signup,denied");
                    this->waitForBytesWritten();
                } else {
                    qDebug() << "sign up: " << account + " " + password;
                    this->write("signup,success");
                    this->waitForBytesWritten();
                }
            }
        }
    }
}

void TcpSocket::login(QString account, QString password) {
    if (!account_db.open()) {
        qDebug() << "database open error";
    } else {
        QSqlQuery qry(account_db);
        /*
        qry.prepare( "DROP TABLE account" );
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
            qDebug() << "Table deleted!";
        */
        qry.prepare("CREATE TABLE IF NOT EXISTS account (id INTEGER UNIQUE PRIMARY KEY, name VARCHAR(30) UNIQUE"
                    ", password VARCHAR(30), status INT DEFAULT 0, winfights INT DEFAULT 0, totalfights INT DEFAULT 0, num INT DEFAULT 0)");
        if (!qry.exec())
            qDebug() << qry.lastError();

        qry.prepare("SELECT name,password,status FROM account WHERE name = ?");
        qry.bindValue(0, "\'" + account + "\'");
        if (!qry.exec()) {
            qDebug() << qry.lastError();
        } else {
            if (qry.next()) {
                QString name = qry.value(0).toString();
                QString db_password = qry.value(1).toString();
                bool status = qry.value(2).toBool();
                if (db_password != ("\'" + password + "\'")) {
                    qDebug() << "wrong password! " << name << db_password;
                    this->write("login,denied");
                    this->waitForBytesWritten();
                } else {
                    if (status) {
                        qDebug() << "already online! " << name << password;
                        this->write("login,already online");
                        this->waitForBytesWritten();
                    } else {
                        qry.prepare("UPDATE account SET status = 1 WHERE name = ?");
                        qry.bindValue(0, "\'" + account + "\'");
                        if (!qry.exec()) {
                            qDebug() << "login failed: " << name;
                            this->write("login,server error");
                            this->waitForBytesWritten();
                        } else {
                            //qDebug() << "send: login permitted";
                            this->write("login,success");
                            this->waitForBytesWritten();
                        }
                    }
                }
            } else {
                qDebug() << "no data";
            }

        }
    }
    //account_db.close();
}

void TcpSocket::logout(QString account) {
    if (!account_db.open()) {
        qDebug() << "database open error";
    } else {
        QSqlQuery qry(account_db);
        qry.prepare("SELECT name,password,status FROM account WHERE name = ?");
        qry.bindValue(0, "\'" + account + "\'");
        if (!qry.exec()) {
            qDebug() << qry.lastError();
            this->write("logout,failed");
            this->waitForBytesWritten();
        } else {
            if (qry.next()) {
                QString name = qry.value(0).toString();
                bool status = qry.value(2).toBool();
                if (!status) {
                    qDebug() << "already online! " << name;
                } else {
                    qry.prepare("UPDATE account SET status = 0 WHERE name = ?");
                    qry.bindValue(0, "\'" + account + "\'");
                    if (!qry.exec()) {
                        qDebug() << "logoff failed: " << name;
                        this->write("logoff,failed");
                        this->waitForBytesWritten();
                    } else {
                        qDebug() << "send: logoff permitted";
                        this->write("logoff,success");
                        this->waitForBytesWritten();
                    }
                }

            } else {
                qDebug() << "no account";
            }
        }
    }
}

void TcpSocket::updateUserData(int id, QString account, int winfights, int totalfights, int num) {
    if (!account_db.open()) {
        qDebug() << "database open error";
    } else {
        QSqlQuery qry(account_db);
        qry.prepare("SELECT name,password,status,num FROM account WHERE name = ?");
        qry.bindValue(0, "\'" + account + "\'");
        if (!qry.exec()) {
            qDebug() << qry.lastError();
            this->write("error,no account");
            this->waitForBytesWritten();
        } else {
            if (qry.next()) {
                QString name = qry.value(0).toString();
                bool status = qry.value(2).toBool();
                if (!status) {
                    qDebug() << "update user failed, not online" << name;
                    this->write("update user,not online");
                    this->waitForBytesWritten();
                } else {
                    qry.prepare("UPDATE account SET num = ?, winfights = ?, totalfights = ? WHERE name = ?");
                    qry.bindValue(0, num);
                    qry.bindValue(1, winfights);
                    qry.bindValue(2, totalfights);
                    qry.bindValue(3, "\'" + account + "\'");
                    if (!qry.exec()) {
                        qDebug() << "update user failed: " << name;
                        this->write("update user,failed");
                        this->waitForBytesWritten();
                    } else {
                        qDebug() << "send: update user success";
                        this->write("update user,success");
                        this->waitForBytesWritten();
                    }
                }

            } else {
                qDebug() << "update user failed no account";
                this->write("update user,no account");
                this->waitForBytesWritten();
            }
        }
    }
}

void TcpSocket::updateCreature(QString data) {
    if (!creature_db.open()) {
        qDebug() << "creature data open error";
        this->write("update creature,data open error");
        this->waitForBytesWritten();
    } else {
        int id = data.section(',', 0, 0).toInt();
        QString name = data.section(',', 1, 1);
        int type = data.section(',', 2, 2).toInt();
        int property = data.section(',', 3, 3).toInt();
        int level = data.section(',', 4, 4).toInt();
        int exp = data.section(',', 5, 5).toInt();
        float strength = data.section(',', 6, 6).toFloat();
        float defense = data.section(',', 7, 7).toFloat();
        int hp = data.section(',', 8, 8).toInt();
        float speed = data.section(',', 9, 9).toFloat();
        QString master = data.section(',', 10, 10);
        QSqlQuery qry(creature_db);
        qry.prepare(
                "CREATE TABLE IF NOT EXISTS creature (id INTEGER UNIQUE PRIMARY KEY, master VARCHAR(30), name VARCHAR(30), type INT"
                ", property INT, level INT, exp INT, strength FLOAT, defense FLOAT, hp INT, speed FLOAT)");
        if (!qry.exec()) {
            qDebug() << "update creature error";
            //this->write("update creature, error");
            //this->waitForBytesWritten();
        }
        qry.prepare("SELECT id,master,name FROM creature WHERE id = ?");
        qry.bindValue(0, id);
        if (!qry.exec()) {
            qDebug() << "select creature error";
        } else {
            if (qry.next()) {
                qry.prepare("UPDATE creature SET name = ?,master = ?,type = ?,property = ?"
                            "level = ?,exp = ?,strength = ?,defense = ?,hp = ?,speed = ? WHERE id = ?");
                qry.bindValue(0, "\'" + name + "\'");
                qry.bindValue(1, "\'" + master + "\'");
                qry.bindValue(2, type);
                qry.bindValue(3, property);
                qry.bindValue(4, level);
                qry.bindValue(5, exp);
                qry.bindValue(6, strength);
                qry.bindValue(7, defense);
                qry.bindValue(8, hp);
                qry.bindValue(9, speed);
                qry.bindValue(10, id);
                if (!qry.exec()) {
                    qDebug() << "update creature error";
                    this->write("update creature,server error");
                    this->waitForBytesWritten();
                } else {
                    //qDebug() << "update creature success";
                }
            } else {
                qry.prepare("INSERT INTO creature (name,master,type,property,level,exp,strength,defense,hp,speed,id)"
                            " VALUES (?,?,?,?,?,?,?,?,?,?,?)");
                qry.bindValue(0, "\'" + name + "\'");
                qry.bindValue(1, "\'" + master + "\'");
                qry.bindValue(2, type);
                qry.bindValue(3, property);
                qry.bindValue(4, level);
                qry.bindValue(5, exp);
                qry.bindValue(6, strength);
                qry.bindValue(7, defense);
                qry.bindValue(8, hp);
                qry.bindValue(9, speed);
                qry.bindValue(10, id);
                if (!qry.exec()) {
                    qDebug() << "insert creature error";
                    this->write("update creature,server error");
                    this->waitForBytesWritten();
                } else {
                    //qDebug() << "insert creature success";
                }
            }
        }
    }
}

void TcpSocket::getUserData(QString account) {
    if (!account_db.open()) {
        qDebug() << "database open error";
    } else {
        QSqlQuery qry(account_db);
        qry.prepare("SELECT id,name,winfights,totalfights,num FROM account WHERE name = ?");
        qry.bindValue(0, "\'" + account + "\'");
        if (!qry.exec()) {
            qDebug() << qry.lastError();
            this->write("login,no account");
            this->waitForBytesWritten();
        } else {
            if (qry.next()) {
                int id = qry.value(0).toInt();
                QString name = qry.value(1).toString();
                int winfights = qry.value(2).toInt();
                int totalfights = qry.value(3).toInt();
                int num = qry.value(4).toInt();
                QString data = "";
                data.append(QString::number(id) + ',');
                data.append(name + ',');
                data.append(QString::number(winfights) + ',');
                data.append(QString::number(totalfights) + ',');
                data.append(QString::number(num));

            } else {
                qDebug() << "update user failed no account";
                this->write("update user,no account");
                this->waitForBytesWritten();
            }
        }
    }
}

void TcpSocket::getCreaetureData(QString) {

}
