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
	FlightInfo();
	FlightInfo(QString flight_id, QString from_airport, QString dst_airport, QBitArray days, QTime departure_time, QTime arrival_time, 
		QMap<QString, size_t> seats, QMap<QString, size_t> price, FlightStatus status, FlightType type);
	~FlightInfo();
	
	QBitArray getDays();
	QTime getDepartureTime();
	QTime getArrivalTime();
	QString getFromAirport();
	QString getDstAirport();
	QString getFlightId();
	QMap<QString, size_t> getSeats();
	QMap<QString, size_t> getPrice();
	FlightStatus getStatus();
	FlightType getType();
	

	bool operator<(const FlightInfo& other) const;
};

