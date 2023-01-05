#include "FlightInfo.h"

FlightInfo::FlightInfo() 
{ // The empty info, using to show false value.
	flight_id = "ERROR";
}

FlightInfo::FlightInfo(QString flight_id, QString from_airport, QString dst_airport, QBitArray days, QTime departure_time, 
	QTime arrival_time, QMap<QString, size_t> seats, QMap<QString, size_t> price, int status, int type, 
	int aircraft)
{
	this->flight_id = flight_id;
	this->from_airport = from_airport;
	this->dst_airport = dst_airport;
	this->days = days;
	this->departure_time = departure_time;
	this->arrival_time = arrival_time;
	this->seats = seats;
	this->price = price;
	this->status = (FlightStatus)status;
	this->type = (FlightType)type;
	this->aircraft = (AircraftType)aircraft;
}

FlightInfo::~FlightInfo()
{}

bool FlightInfo::operator<(const FlightInfo& other) const
{
	return this->flight_id < other.flight_id;
}

QBitArray FlightInfo::getDays()
{
	return days;
}

QTime FlightInfo::getDepartureTime()
{
	return departure_time;
}

QTime FlightInfo::getArrivalTime()
{
	return arrival_time;
}

QString FlightInfo::getFlightId()
{
	return flight_id;
}

QString FlightInfo::getFromAirport()
{
	return from_airport;
}

QString FlightInfo::getDstAirport()
{
	return dst_airport;
}

QMap<QString, size_t> FlightInfo::getSeats()
{
	return seats;
}

QMap<QString, size_t> FlightInfo::getPrice()
{
	return price;
}

FlightInfo::FlightStatus FlightInfo::getStatus()
{
	return status;
}

FlightInfo::FlightType FlightInfo::getType()
{
	return type;
}

FlightInfo::AircraftType FlightInfo::getAircraft()
{
	return aircraft;
}

