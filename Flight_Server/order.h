/**
 * @file order.h
 * @author yangyf83
 * @brief 
 * @version 0.1
 * @date 2022-09-07
 * 
 * @copyright Copyright (c) 2022 with MIT License
 * 
 */

#pragma once

#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDateTime>


enum class OrderStatus { 
    UNPAID, 
    PAID, 
    CANCELED
};

class Order
{
private:
    int orderID;
    QString user_id;
    QString flight_id;
    int seat;
    int price;
    OrderStatus status;
    bool writeToLog(QString log_info);
public:
    Order(int orderID, QString user_id, QString flight_id, int seat, int price, OrderStatus status);
    ~Order();
    QString getUserID() const;
    OrderStatus getStatus() const;
    QString getFlightID() const;
    int getSeat() const;
    int getPrice() const;
    int getOrderID() const;

    void pay();
    void cancel();
    bool writeToDB(QSqlDatabase db);
};
