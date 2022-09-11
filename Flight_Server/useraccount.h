/**
 * @file useraccount.h
 * @author yangyf83
 * @brief The header file of UserAccount class
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022 with MIT License
 * TODO: Add sql operations
 */

#pragma once

#include <QString>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QFile>
#include <QCryptographicHash>

class UserAccount
{
private:
    QString user_id;
    QString username;
    QByteArray password_hash;
    QString email;
    QString phone;
    QString name;
    QString surname;

    QString address;

    QString passport_number;
    QString passport_expiration_date;
    QString passport_issuing_country;
    QString passport_issuing_date;
    QString passport_issuing_authority;
    QString passport_birth_place;
    QString passport_birth_date;

    bool writeToLog(QString log_info);
public:
    static QByteArray getHashedPassword(const QString password);

    UserAccount(QString username, QByteArray password_hash, QString phone, QString name, QString surname, QString address, QString passport_number, QString passport_expiration_date, QString passport_issuing_country, QString passport_issuing_date, QString passport_issuing_authority, QString passport_birth_place, QString passport_birth_date, QString email = "");
    ~UserAccount();

    QString getUsername() const;
    QByteArray getPasswordHash() const;
    QString getEmail() const;
    QString getPhone() const;
    QString getName() const;
    QString getSurname() const;
    QString getAddress() const;
    QString getPassportNumber() const;
    QString getPassportExpirationDate() const;
    QString getPassportIssuingCountry() const;
    QString getPassportIssuingDate() const;
    QString getPassportIssuingAuthority() const;
    QString getPassportBirthPlace() const;
    QString getPassportBirthDate() const;
    QString getPassport() const;

    bool WriteToDB(QSqlDatabase DB);
};
