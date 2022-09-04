/**
 * @file flightinfo.h
 * @author yangyf83
 * @brief The header file of FlightInfo class
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022 with MIT License
 * 
 */

#pragma once
#include <QString>
#include <QDateTime>

enum class FlightType
{
    planing,
    boarding,
    flying,
    landed,
    canceled,
    delayed,
    unknown
};

enum class AircraftType
{
    a320,
    a330,
    a340,
    a350,
    a380,
    b737,
    b747,
    b757,
    b767,
    b777,
    b787,
    unknown
};

class FlightInfo
{
private:
    QString flight_id;
    QString flight_name;
    FlightType flight_type;
    AircraftType aircraft_type;
    QString departure_airport;
    QString arrival_airport;
    QDateTime departure_time;
    QDateTime arrival_time;

    QDateTime departure_time_change;
    QDateTime arrival_time_change;
    QString departure_time_change_reason;
    QString arrival_time_change_reason;
    QString cancel_reason;

    QString departure_checkin;
    QString arrival_checkin;
    QString departure_boarding;
    QString arrival_boarding;

    QString departure_gate;
    QString arrival_gate;

    QString departure_gate_change;
    QString arrival_gate_change;
    QString departure_gate_change_reason;
    QString arrival_gate_change_reason;

public:
    // TODO: add the time and status check in the SQL function
    FlightInfo(const QString &flight_id, const QString &flight_name, const FlightType &flight_type, const AircraftType &aircraft_type, const QString &departure_airport, const QString &arrival_airport, const QDateTime &departure_time, const QDateTime &arrival_time, const QString &departure_checkin, const QString &arrival_checkin, const QString &departure_boarding, const QString &arrival_boarding, const QString &departure_gate, const QString &arrival_gate);

    QString getFlightId() const;
    QString getFlightName() const;
    FlightType getFlightType() const;
    AircraftType getAircraftType() const;
    QString getDepartureAirport() const;
    QString getArrivalAirport() const;
    QDateTime getDepartureTime() const;
    QDateTime getArrivalTime() const;
    QString getDepartureCheckin() const;
    QString getArrivalCheckin() const;
    QString getDepartureBoarding() const;
    QString getArrivalBoarding() const;
    QString getDepartureGate() const;
    QString getArrivalGate() const;

    // change
    bool changeDepartureTime(const QDateTime &new_departure_time, const QString &reason);
    bool changeArrivalTime(const QDateTime &new_arrival_time, const QString &reason);
    bool changeDepartureGate(const QString &new_departure_gate, const QString &reason);
    bool changeArrivalGate(const QString &new_arrival_gate, const QString &reason);
    bool cancelFlight(const QString &reason);

    bool operator==(const FlightInfo &other) const;
    bool operator!=(const FlightInfo &other) const;

    // set status
    void setFlightType(const FlightType &flight_type);
};
