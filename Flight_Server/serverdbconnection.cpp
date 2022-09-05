#include "serverdbconnection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

ServerDBConnection::ServerDBConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("mysql");
    db.setUserName("root");
    db.setPassword("");
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
