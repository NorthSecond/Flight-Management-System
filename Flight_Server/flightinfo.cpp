/**
 * @file flightinfo.cpp
 * @author yangyf83
 * @brief The implementation file of FlightInfo class
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022 with MIT License
 * 
 */

#include "flightinfo.h"

#include <QDateTime>
#include <QString>

QString FlightInfo::getFlightId() const
{
    return flight_id;
}

QString FlightInfo::getFlightName() const
{
    return flight_name;
}

QString FlightInfo::getDepartureAirport() const
{
    return departure_airport;
}

QString FlightInfo::getArrivalAirport() const
{
    return arrival_airport;
}

QDateTime FlightInfo::getDepartureTime() const
{
    return departure_time;
}

QDateTime FlightInfo::getArrivalTime() const
{
    return arrival_time;
}

QString FlightInfo::getDepartureCheckin() const
{
    return departure_checkin;
}

QString FlightInfo::getArrivalCheckin() const
{
    return arrival_checkin;
}

QString FlightInfo::getDepartureBoarding() const
{
    return departure_boarding;
}

QString FlightInfo::getArrivalBoarding() const
{
    return arrival_boarding;
}

QString FlightInfo::getDepartureGate() const
{
    return departure_gate;
}

QString FlightInfo::getArrivalGate() const
{
    return arrival_gate;
}

FlightType FlightInfo::getFlightType() const
{
    return flight_type;
}

AircraftType FlightInfo::getAircraftType() const
{
    return aircraft_type;
}

bool FlightInfo::changeDepartureTime(const QDateTime &new_departure_time, const QString &reason)
{
    if (new_departure_time < departure_time)
    {
        return false;
    }
    departure_time_change = new_departure_time;
    departure_time_change_reason = reason;
    arrival_time_change = arrival_time.addSecs(departure_time.secsTo(new_departure_time));
    flight_type = FlightType::delayed;
    return true;
}

bool FlightInfo::changeArrivalTime(const QDateTime &new_arrival_time, const QString &reason)
{
    if (new_arrival_time < arrival_time)
    {
        return false;
    }
    arrival_time_change = new_arrival_time;
    arrival_time_change_reason = reason;
    flight_type = FlightType::delayed;
    return true;
}

bool FlightInfo::changeDepartureGate(const QString &new_departure_gate, const QString &reason)
{
    departure_gate_change = new_departure_gate;
    departure_gate_change_reason = reason;
    return true;
}

bool FlightInfo::changeArrivalGate(const QString &new_arrival_gate, const QString &reason)
{
    arrival_gate_change = new_arrival_gate;
    arrival_gate_change_reason = reason;
    return true;
}

bool FlightInfo::cancelFlight(const QString &reason)
{
    if (QTime::currentTime() > departure_time.time() || flight_type == FlightType::canceled)
    {
        return false;
    }
    flight_type = FlightType::canceled;
    cancel_reason = reason;
    return true;
}

void FlightInfo::setFlightType(const FlightType& type)
{
    flight_type = type;
}

bool FlightInfo::operator==(const FlightInfo &other) const
{
    return flight_id == other.flight_id && departure_time == other.departure_time;
}

bool FlightInfo::operator!=(const FlightInfo &other) const
{
    return !(*this == other);
}
