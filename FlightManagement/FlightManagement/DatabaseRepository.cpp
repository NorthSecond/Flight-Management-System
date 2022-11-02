#include "DatabaseRepository.h"

DatabaseRepository::DatabaseRepository()
{
	QString hostName = "localhost";
	int port = 3306;
	QString databaseName = "FlightManagement";
	QString userName = "root";
	QString password = "357480";
	initializeDatabase(hostName, port, databaseName, userName, password);
}

DatabaseRepository::~DatabaseRepository()
{
	db.close();
}

void DatabaseRepository::initializeDatabase(QString hostName, int port, QString databaseName, QString userName, QString password)
{
	db = QSqlDatabase::addDatabase("QODBC");
	db.setHostName(hostName);
	db.setPort(port);
	db.setDatabaseName(databaseName);
	db.setUserName(userName);
	db.setPassword(password);
	if (!db.open())
	{// fail to open database
		QMessageBox::critical(NULL, "Error", "Database connection failed!");
	}
}

FlightInfo DatabaseRepository::getFlightInfo(QString flight_id)
{
	QSqlQuery query;
	query.prepare("SELECT * FROM FlightInfo WHERE flight_id = :flight_id");
	query.bindValue(":flight_id", flight_id);
	query.exec();
	if (query.next())
	{
		QString flight_id = query.value(0).toString();
		QString from_airport = query.value(1).toString();
		QString dst_airport = query.value(2).toString();
		QBitArray days(7);
		days.setBit(0, query.value(3).toBool());
		days.setBit(1, query.value(4).toBool());
		days.setBit(2, query.value(5).toBool());
		days.setBit(3, query.value(6).toBool());
		days.setBit(4, query.value(7).toBool());
		days.setBit(5, query.value(8).toBool());
		days.setBit(6, query.value(9).toBool());
		QTime departure_time = query.value(10).toTime();
		QTime arrival_time = query.value(11).toTime();
		QMap<QString, size_t> seats;
		seats.insert("Economy", query.value(12).toUInt());
		seats.insert("Business", query.value(13).toUInt());
		seats.insert("First", query.value(14).toUInt());
		QMap<QString, size_t> price;
		price.insert("Economy", query.value(15).toUInt());
		price.insert("Business", query.value(16).toUInt());
		price.insert("First", query.value(17).toUInt());
		FlightInfo::FlightStatus status = (FlightInfo::FlightStatus)query.value(18).toUInt();
		FlightInfo::FlightType type = (FlightInfo::FlightType)query.value(19).toUInt();
		return FlightInfo(flight_id, from_airport, dst_airport, days, departure_time, arrival_time, seats, price, status, type);
	}
	else
	{
		return FlightInfo();
	}
}

QVector<FlightInfo> DatabaseRepository::getFlightInfo(QString from_airport, QString dst_airport, QDate date)
{
	QVector<FlightInfo> flight_infos;
	QSqlQuery query;
	query.prepare("SELECT * FROM FlightInfo WHERE from_airport = :from_airport AND dst_airport = :dst_airport");
	query.bindValue(":from_airport", from_airport);
	query.bindValue(":dst_airport", dst_airport);
	query.exec();
	while (query.next())
	{
		QString flight_id = query.value(0).toString();
		QString from_airport = query.value(1).toString();
		QString dst_airport = query.value(2).toString();
		QBitArray days(7);
		days.setBit(0, query.value(3).toBool());
		days.setBit(1, query.value(4).toBool());
		days.setBit(2, query.value(5).toBool());
		days.setBit(3, query.value(6).toBool());
		days.setBit(4, query.value(7).toBool());
		days.setBit(5, query.value(8).toBool());
		days.setBit(6, query.value(9).toBool());
		QTime departure_time = query.value(10).toTime();
		QTime arrival_time = query.value(11).toTime();
		QMap<QString, size_t> seats;
		seats.insert("Economy", query.value(12).toUInt());
		seats.insert("Business", query.value(13).toUInt());
		seats.insert("First", query.value(14).toUInt());
		QMap<QString, size_t> price;
		price.insert("Economy", query.value(15).toUInt());
		price.insert("Business", query.value(16).toUInt());
		price.insert("First", query.value(17).toUInt());
		FlightInfo::FlightStatus status = (FlightInfo::FlightStatus)query.value(18).toUInt();
		FlightInfo::FlightType type = (FlightInfo::FlightType)query.value(19).toUInt();
		FlightInfo flight_info(flight_id, from_airport, dst_airport, days, departure_time, arrival_time, seats, price, status, type);
		if (flight_info.getDays().testBit(date.dayOfWeek() - 1))
		{
			flight_infos.push_back(flight_info);
		}
	}
	return flight_infos;
}

QVector <FlightInfo> DatabaseRepository::getFlightInfo(QVector<QString> flight_ids)
{
	QVector<FlightInfo> flight_infos;
	QSqlQuery query;
	for (QString& flight_id : flight_ids)
	{
		query.prepare("SELECT * FROM FlightInfo WHERE flight_id = :flight_id");
		query.bindValue(":flight_id", flight_id);
		query.exec();
		if (query.next())
		{
			QString flight_id = query.value(0).toString();
			QString from_airport = query.value(1).toString();
			QString dst_airport = query.value(2).toString();
			QBitArray days(7);
			days.setBit(0, query.value(3).toBool());
			days.setBit(1, query.value(4).toBool());
			days.setBit(2, query.value(5).toBool());
			days.setBit(3, query.value(6).toBool());
			days.setBit(4, query.value(7).toBool());
			days.setBit(5, query.value(8).toBool());
			days.setBit(6, query.value(9).toBool());
			QTime departure_time = query.value(10).toTime();
			QTime arrival_time = query.value(11).toTime();
			QMap<QString, size_t> seats;
			seats.insert("Economy", query.value(12).toUInt());
			seats.insert("Business", query.value(13).toUInt());
			seats.insert("First", query.value(14).toUInt());
			QMap<QString, size_t> price;
			price.insert("Economy", query.value(15).toUInt());
			price.insert("Business", query.value(16).toUInt());
			price.insert("First", query.value(17).toUInt());
			FlightInfo::FlightStatus status = (FlightInfo::FlightStatus)query.value(18).toUInt();
			FlightInfo::FlightType type = (FlightInfo::FlightType)query.value(19).toUInt();
			FlightInfo flight_info(flight_id, from_airport, dst_airport, days, departure_time, arrival_time, seats, price, status, type);
			flight_infos.push_back(flight_info);
		}
	}
	return flight_infos;
}

QVector<FlightInfo> DatabaseRepository::getFlightInfo(QString from_airport, QString dst_airport, QDate date, FlightInfo::FlightType type)
{
	QVector<FlightInfo> flight_infos;
	QSqlQuery query;
	query.prepare("SELECT * FROM FlightInfo WHERE from_airport = :from_airport AND dst_airport = :dst_airport AND type = :type");
	query.bindValue(":from_airport", from_airport);
	query.bindValue(":dst_airport", dst_airport);
	query.bindValue(":type", type);
	query.exec();
	while (query.next())
	{
		QString flight_id = query.value(0).toString();
		QString from_airport = query.value(1).toString();
		QString dst_airport = query.value(2).toString();
		QBitArray days(7);
		days.setBit(0, query.value(3).toBool());
		days.setBit(1, query.value(4).toBool());
		days.setBit(2, query.value(5).toBool());
		days.setBit(3, query.value(6).toBool());
		days.setBit(4, query.value(7).toBool());
		days.setBit(5, query.value(8).toBool());
		days.setBit(6, query.value(9).toBool());
		QTime departure_time = query.value(10).toTime();
		QTime arrival_time = query.value(11).toTime();
		QMap<QString, size_t> seats;
		seats.insert("Economy", query.value(12).toUInt());
		seats.insert("Business", query.value(13).toUInt());
		seats.insert("First", query.value(14).toUInt());
		QMap<QString, size_t> price;
		price.insert("Economy", query.value(15).toUInt());
		price.insert("Business", query.value(16).toUInt());
		price.insert("First", query.value(17).toUInt());
		FlightInfo::FlightStatus status = (FlightInfo::FlightStatus)query.value(18).toUInt();
		FlightInfo::FlightType type = (FlightInfo::FlightType)query.value(19).toUInt();
		FlightInfo flight_info(flight_id, from_airport, dst_airport, days, departure_time, arrival_time, seats, price, status, type);
		if (flight_info.getDays().testBit(date.dayOfWeek() - 1))
		{
			flight_infos.push_back(flight_info);
		}
	}
	return flight_infos;
}

QVector<FlightInfo> DatabaseRepository::getFlightInfo(QString from_airport, QString dst_airport, QDate date, FlightInfo::FlightStatus status)
{
	QVector<FlightInfo> flight_infos;
	QSqlQuery query;
	query.prepare("SELECT * FROM FlightInfo WHERE from_airport = :from_airport AND dst_airport = :dst_airport AND status = :status");
	query.bindValue(":from_airport", from_airport);
	query.bindValue(":dst_airport", dst_airport);
	query.bindValue(":status", status);
	query.exec();
	while (query.next())
	{
		QString flight_id = query.value(0).toString();
		QString from_airport = query.value(1).toString();
		QString dst_airport = query.value(2).toString();
		QBitArray days(7);
		days.setBit(0, query.value(3).toBool());
		days.setBit(1, query.value(4).toBool());
		days.setBit(2, query.value(5).toBool());
		days.setBit(3, query.value(6).toBool());
		days.setBit(4, query.value(7).toBool());
		days.setBit(5, query.value(8).toBool());
		days.setBit(6, query.value(9).toBool());
		QTime departure_time = query.value(10).toTime();
		QTime arrival_time = query.value(11).toTime();
		QMap<QString, size_t> seats;
		seats.insert("Economy", query.value(12).toUInt());
		seats.insert("Business", query.value(13).toUInt());
		seats.insert("First", query.value(14).toUInt());
		QMap<QString, size_t> price;
		price.insert("Economy", query.value(15).toUInt());
		price.insert("Business", query.value(16).toUInt());
		price.insert("First", query.value(17).toUInt());
		FlightInfo::FlightStatus status = (FlightInfo::FlightStatus)query.value(18).toUInt();
		FlightInfo::FlightType type = (FlightInfo::FlightType)query.value(19).toUInt();
		FlightInfo flight_info(flight_id, from_airport, dst_airport, days, departure_time, arrival_time, seats, price, status, type);
		if (flight_info.getDays().testBit(date.dayOfWeek() - 1))
		{
			flight_infos.push_back(flight_info);
		}
	}
	return flight_infos;
}

QVector<FlightInfo> DatabaseRepository::getFlightInfo(QString from_airport, QString dst_airport, QDate date, FlightInfo::FlightType type, FlightInfo::FlightStatus status)
{
	QVector<FlightInfo> flight_infos;
	QSqlQuery query;
	query.prepare("SELECT * FROM FlightInfo WHERE from_airport = :from_airport AND dst_airport = :dst_airport AND type = :type AND status = :status");
	query.bindValue(":from_airport", from_airport);
	query.bindValue(":dst_airport", dst_airport);
	query.bindValue(":type", type);
	query.bindValue(":status", status);
	query.exec();
	while (query.next())
	{
		QString flight_id = query.value(0).toString();
		QString from_airport = query.value(1).toString();
		QString dst_airport = query.value(2).toString();
		QBitArray days(7);
		days.setBit(0, query.value(3).toBool());
		days.setBit(1, query.value(4).toBool());
		days.setBit(2, query.value(5).toBool());
		days.setBit(3, query.value(6).toBool());
		days.setBit(4, query.value(7).toBool());
		days.setBit(5, query.value(8).toBool());
		days.setBit(6, query.value(9).toBool());
		QTime departure_time = query.value(10).toTime();
		QTime arrival_time = query.value(11).toTime();
		QMap<QString, size_t> seats;
		seats.insert("Economy", query.value(12).toUInt());
		seats.insert("Business", query.value(13).toUInt());
		seats.insert("First", query.value(14).toUInt());
		QMap<QString, size_t> price;
		price.insert("Economy", query.value(15).toUInt());
		price.insert("Business", query.value(16).toUInt());
		price.insert("First", query.value(17).toUInt());
		FlightInfo::FlightStatus status = (FlightInfo::FlightStatus)query.value(18).toUInt();
		FlightInfo::FlightType type = (FlightInfo::FlightType)query.value(19).toUInt();
		FlightInfo flight_info(flight_id, from_airport, dst_airport, days, departure_time, arrival_time, seats, price, status, type);
		if (flight_info.getDays().testBit(date.dayOfWeek() - 1))
		{
			flight_infos.push_back(flight_info);
		}
	}
	return flight_infos;
}

bool DatabaseRepository::addFlightInfo(FlightInfo flight_info) 
{
		QSqlQuery query;
		query.prepare("INSERT INTO FlightInfo (flight_id, from_airport, dst_airport, monday, tuesday, wednesday, thursday, friday, saturday, sunday, departure_time, arrival_time, economy_seats, business_seats, first_seats, economy_price, business_price, first_price, status, type) VALUES (:flight_id, :from_airport, :dst_airport, :monday, :tuesday, :wednesday, :thursday, :friday, :saturday, :sunday, :departure_time, :arrival_time, :economy_seats, :business_seats, :first_seats, :economy_price, :business_price, :first_price, :status, :type)");
		query.bindValue(":flight_id", flight_info.getFlightId());
		query.bindValue(":from_airport", flight_info.getFromAirport());
		query.bindValue(":dst_airport", flight_info.getDstAirport());
		query.bindValue(":monday", flight_info.getDays().testBit(0));
		query.bindValue(":tuesday", flight_info.getDays().testBit(1));
		query.bindValue(":wednesday", flight_info.getDays().testBit(2));
		query.bindValue(":thursday", flight_info.getDays().testBit(3));
		query.bindValue(":friday", flight_info.getDays().testBit(4));
		query.bindValue(":saturday", flight_info.getDays().testBit(5));
		query.bindValue(":sunday", flight_info.getDays().testBit(6));
		query.bindValue(":departure_time", flight_info.getDepartureTime());
		query.bindValue(":arrival_time", flight_info.getArrivalTime());
		query.bindValue(":economy_seats", flight_info.getSeats().value("Economy"));
		query.bindValue(":business_seats", flight_info.getSeats().value("Business"));
		query.bindValue(":first_seats", flight_info.getSeats().value("First"));
		query.bindValue(":economy_price", flight_info.getPrice().value("Economy"));
		query.bindValue(":business_price", flight_info.getPrice().value("Business"));
		query.bindValue(":first_price", flight_info.getPrice().value("First"));
		query.bindValue(":status", flight_info.getStatus());
		query.bindValue(":type", flight_info.getType());
		return query.exec();
}

bool DatabaseRepository::addFlightInfo(QVector<FlightInfo> flight_infos) 
{
	QSqlQuery query;
	QString sentence = "INSERT INTO FlightInfo (flight_id, from_airport, dst_airport, monday, tuesday, wednesday, thursday, friday, saturday, sunday, departure_time, arrival_time, economy_seats, business_seats, first_seats, economy_price, business_price, first_price, status, type) VALUES ";
	QString tmpStr;
	for (auto i : flight_infos) {
		tmpStr = "(";
		tmpStr += i.getFlightId();
		tmpStr += ", ";
		tmpStr += i.getFromAirport();
		tmpStr += ", ";
		tmpStr += i.getDstAirport();
		tmpStr += ", ";
		tmpStr += i.getDays().testBit(0) ? "1" : "0";
		tmpStr += ", ";
		tmpStr += i.getDays().testBit(1) ? "1" : "0";
		tmpStr += ", ";
		tmpStr += i.getDays().testBit(2) ? "1" : "0";
		tmpStr += ", ";
		tmpStr += i.getDays().testBit(3) ? "1" : "0";
		tmpStr += ", ";
		tmpStr += i.getDays().testBit(4) ? "1" : "0";
		tmpStr += ", ";
		tmpStr += i.getDays().testBit(5) ? "1" : "0";
		tmpStr += ", ";
		tmpStr += i.getDays().testBit(6) ? "1" : "0";
		tmpStr += ", ";
		tmpStr += i.getDepartureTime().toString("hh:mm:ss");
		tmpStr += ", ";
		tmpStr += i.getArrivalTime().toString("hh:mm:ss");
		tmpStr += ", ";
		tmpStr += QString::number(i.getSeats().value("Economy"));
		tmpStr += ", ";
		tmpStr += QString::number(i.getSeats().value("Business"));
		tmpStr += ", ";
		tmpStr += QString::number(i.getSeats().value("First"));
		tmpStr += ", ";
		tmpStr += QString::number(i.getPrice().value("Economy"));
		tmpStr += ", ";
		tmpStr += QString::number(i.getPrice().value("Business"));
		tmpStr += ", ";
		tmpStr += QString::number(i.getPrice().value("First"));
		tmpStr += ", ";
		tmpStr += QString::number(i.getStatus());
		tmpStr += ", ";
		tmpStr += QString::number(i.getType());
		tmpStr += "), ";
		sentence += tmpStr;
	}
	return query.exec(); 
}

bool DatabaseRepository::updateFlightInfo(FlightInfo flight_info)
{
	QSqlQuery query;
	query.prepare("UPDATE FlightInfo SET from_airport = :from_airport, dst_airport = :dst_airport, monday = :monday, tuesday = :tuesday, wednesday = :wednesday, thursday = :thursday, friday = :friday, saturday = :saturday, sunday = :sunday, departure_time = :departure_time, arrival_time = :arrival_time, economy_seats = :economy_seats, business_seats = :business_seats, first_seats = :first_seats, economy_price = :economy_price, business_price = :business_price, first_price = :first_price, status = :status, type = :type WHERE flight_id = :flight_id");
	query.bindValue(":flight_id", flight_info.getFlightId());
	query.bindValue(":from_airport", flight_info.getFromAirport());
	query.bindValue(":dst_airport", flight_info.getDstAirport());
	query.bindValue(":monday", flight_info.getDays().testBit(0));
	query.bindValue(":tuesday", flight_info.getDays().testBit(1));
	query.bindValue(":wednesday", flight_info.getDays().testBit(2));
	query.bindValue(":thursday", flight_info.getDays().testBit(3));
	query.bindValue(":friday", flight_info.getDays().testBit(4));
	query.bindValue(":saturday", flight_info.getDays().testBit(5));
	query.bindValue(":sunday", flight_info.getDays().testBit(6));
	query.bindValue(":departure_time", flight_info.getDepartureTime());
	query.bindValue(":arrival_time", flight_info.getArrivalTime());
	query.bindValue(":economy_seats", flight_info.getSeats().value("Economy"));
	query.bindValue(":business_seats", flight_info.getSeats().value("Business"));
	query.bindValue(":first_seats", flight_info.getSeats().value("First"));
	query.bindValue(":economy_price", flight_info.getPrice().value("Economy"));
	query.bindValue(":business_price", flight_info.getPrice().value("Business"));
	query.bindValue(":first_price", flight_info.getPrice().value("First"));
	query.bindValue(":status", flight_info.getStatus());
	query.bindValue(":type", flight_info.getType());
	return query.exec();
}

bool DatabaseRepository::deleteFlightInfo(QString flight_id)
{
	QSqlQuery query;
	query.prepare("DELETE FROM FlightInfo WHERE flight_id = :flight_id");
	query.bindValue(":flight_id", flight_id);
	return query.exec();
}
