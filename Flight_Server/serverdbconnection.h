/**
 * @file serverdbconnection.h
 * @author yangyf83
 * @brief The util class for connecting to the database
 * @version 0.1
 * @date 2022-09-05
 * 
 * @copyright Copyright (c) 2022 with MIT License
 * 
 */

#pragma once
#include <QSqlDatabase>

class ServerDBConnection
{
private:
    QSqlDatabase db;
public:
    ServerDBConnection();
    ~ServerDBConnection();
    bool connect();
    bool disconnect();
    bool isConnected();
    QSqlDatabase getDB();
};

