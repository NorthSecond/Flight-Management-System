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
#include "useraccount.h"
#include "flightinfo.h"
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
public:
    Order(int orderID, Qstring user_id, QString flight_id, int seat, int price, OrderStatus status);
    ~Order();
    QString getUserID() const;
    OrderedStatus getStatus() const;
    QString getFlightID() const;
    int getSeat() const;
    int getPrice() const;
    int getOrderID() const;

    void pay();
    void cancel();
    bool writeToDB(QDatabase db);
    bool writeToLog(QString loginfo);
};