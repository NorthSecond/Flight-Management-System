#include "serverdbconnection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

ServerDBConnection::ServerDBConnection(QString hostName, int port, QString databaseName, QString userName, QString password)
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName(hostName);
    db.setPort(port);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);
}

ServerDBConnection::~ServerDBConnection()
{
    if (db.isOpen())
    {
        db.close();
    }
}

bool ServerDBConnection::connect()
{
    return ok = db.open();
}

bool ServerDBConnection::disconnect()
{
    if (db.isOpen())
    {
        db.close();
        return true;
    }
    return false;
}

bool ServerDBConnection::isConnected()
{
    return db.isOpen();
}

QSqlDatabase ServerDBConnection::getDB()
{
    return db;
}
