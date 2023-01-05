#pragma once

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>

#include "FlightInfo.h"

class DatabaseRepository
{
private:
	QSqlDatabase db;
	void initializeDatabase(QString hostName, int port, QString databaseName, QString userName, QString password);
public:
	DatabaseRepository();
	~DatabaseRepository();
	FlightInfo getFlightInfo(QString flight_id);
	QVector<FlightInfo> getFlightInfo(QString from_airport, QString dst_airport, QDate date);
	QVector<FlightInfo> getFlightInfo(QVector<QString> flight_ids);
	QVector<FlightInfo> getFlightInfo(QString from_airport, QString dst_airport, QDate date, FlightInfo::FlightType type);
	QVector<FlightInfo> getFlightInfo(QString from_airport, QString dst_airport, QDate date, FlightInfo::FlightStatus status);
	QVector<FlightInfo> getFlightInfo(QString from_airport, QString dst_airport, QDate date, FlightInfo::FlightType type, FlightInfo::FlightStatus status);

	bool addFlightInfo(FlightInfo flight_info);
	bool addFlightInfo(QVector<FlightInfo> flight_infos);
	bool updateFlightInfo(FlightInfo flight_info);
	bool deleteFlightInfo(QString flight_id);
	QSqlDatabase getDatabase();
};
