#pragma once

#include <QString>
#include <QVector>
#include <Qtime>
#include <QMap>
#include <QBitarray>

class FlightInfo
{
public:
	enum FlightStatus
	{
		FlightStatusUnknown,
		FlightStatusOnTime,
		FlightStatusDelayed,
		FlightStatusCancelled,
		FlightStatusArrived
	};

	enum FlightType
	{
		FlightTypeUnknown,
		FlightTypeDomestic,
		FlightTypeInternational
	};

	enum AircraftType
	{
		Boeing,
		Airbus,
		Comac,
		Embraer,
		Bombardier,
		Antonov,
		Lockheed,
		McDonnellDouglas,
		DeHavilland,
		Other
	};
private:
	QString flight_id;
	QString from_airport;
	QString dst_airport;
	QBitArray days;
	QTime departure_time;
	QTime arrival_time;
	
	QMap<QString, size_t> seats;
	QMap<QString, size_t> price;
	FlightStatus status;
	FlightType type;
	
public:
	FlightInfo(QString flight_id, QString from_airport, QString dst_airport, QBitArray days, QTime departure_time, QTime arrival_time, 
		QMap<QString, size_t> seats, QMap<QString, size_t> price, FlightStatus status, FlightType type);
	~FlightInfo();

	bool operator<(const FlightInfo& other) const;
};

