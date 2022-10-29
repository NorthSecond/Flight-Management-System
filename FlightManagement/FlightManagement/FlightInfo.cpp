#include "FlightInfo.h"

FlightInfo::FlightInfo(QString flight_id, QString from_airport, QString dst_airport, QBitArray days, QTime departure_time, QTime arrival_time, QMap<QString, size_t> seats, QMap<QString, size_t> price, FlightStatus status, FlightType type)
{
	this->flight_id = flight_id;
	this->from_airport = from_airport;
	this->dst_airport = dst_airport;
	this->days = days;
	this->departure_time = departure_time;
	this->arrival_time = arrival_time;
	this->seats = seats;
	this->price = price;
	this->status = status;
	this->type = type;
}

FlightInfo::~FlightInfo()
{}

bool FlightInfo::operator<(const FlightInfo& other) const
{
	return this->flight_id < other.flight_id;
}
