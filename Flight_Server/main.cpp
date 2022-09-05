#include <QCoreApplication>
#include <QSqlDatabase>

#include "serverdbconnection.h"

int main(int argc, char *argv[])
{
    ServerDBConnection db_connection;
    if (db_connection.connect())
    {
        qDebug() << "Connected to the database";
    }
    else
    {
        qErrnoWarning("Failed to connect to the database");
        return 0;
    }
    QCoreApplication a(argc, argv);
    ServerDBConnection db;
    return a.exec();
}
