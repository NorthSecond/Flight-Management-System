/**
 * @file order.cpp
 * @author yangyf83
 * @brief 
 * @version 0.1
 * @date 2022-09-07
 * 
 * @copyright Copyright (c) 2022 with MIT License
 * 
 */

#include "order.h"

using namespace Qt;

Order::Order(int orderID, QString user_id, QString flight_id, int seat, int price, OrderStatus status)
{
    this->orderID = orderID;
    this->user_id = user_id;
    this->flight_id = flight_id;
    this->seat = seat;
    this->price = price;
    this->status = status;
}

Order::~Order()
{
}

QString Order::getUserID() const
{
    return this->user_id;
}

OrderStatus Order::getStatus() const
{
    return this->status;
}

QString Order::getFlightID() const
{
    return this->flight_id;
}

int Order::getSeat() const
{
    return this->seat;
}

int Order::getPrice() const
{
    return this->price;
}

int Order::getOrderID() const
{
    return this->orderID;
}

void Order::pay()
{
    this->status = OrderStatus::PAID;
    // TODO: write to database
}

void Order::cancel()
{
    this->status = OrderStatus::CANCELED;
    // TODO: write to database
}

bool Order::writeToDB(QSqlDatabase db)
{
    if(!db.isOpen())
    {
        return false;
    }
    QSqlQuery query(db);
    query.prepare("INSERT INTO orders (order_id, user_id, flight_id, seat, price, status) VALUES (:order_id, :user_id, :flight_id, :seat, :price, :status)");
    query.bindValue(":order_id", this->orderID);
    query.bindValue(":user_id", this->user_id);
    query.bindValue(":flight_id", this->flight_id);
    query.bindValue(":seat", this->seat);
    query.bindValue(":price", this->price);
    // TODO: find a good way to store the status of the order.
//    query.bindValue(":status", this->status);
    return query.exec();
}

bool Order::writeToLog(QString loginfo)
{
    QFile file("./logs/order.log");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        return false;
    }
    QTextStream out(&file);
    out << this->user_id  << '\t' << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << loginfo << ":\n\t";
    out << loginfo << Qt::endl;
    return true;
}
