/**
 * @file useraccount.cpp
 * @author yangyf83
 * @brief The implementation file of UserAccount class
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022 with MIT License
 * TODO: Add sql operations
 */

#include "useraccount.h"

#include <QDateTime>
#include <QString>
#include <QCryptographicHash>

UserAccount::UserAccount(QString username, QByteArray password_hash, QString phone, QString name, QString surname, QString address, QString passport_number, QString passport_expiration_date, QString passport_issuing_country, QString passport_issuing_date, QString passport_issuing_authority, QString passport_birth_place, QString passport_birth_date, QString email)
{
    this->username = username;
    this->password_hash = password_hash;
    this->phone = phone;
    this->name = name;
    this->surname = surname;
    this->address = address;
    this->passport_number = passport_number;
    this->passport_expiration_date = passport_expiration_date;
    this->passport_issuing_country = passport_issuing_country;
    this->passport_issuing_date = passport_issuing_date;
    this->passport_issuing_authority = passport_issuing_authority;
    this->passport_birth_place = passport_birth_place;
    this->passport_birth_date = passport_birth_date;
    this->email = email;
}

QString UserAccount::getUsername() const
{
    return username;
}

QByteArray UserAccount::getPasswordHash() const
{
    return password_hash;
}

QString UserAccount::getEmail() const
{
    return email;
}

QString UserAccount::getPhone() const
{
    return phone;
}

QString UserAccount::getName() const
{
    return name;
}

QString UserAccount::getSurname() const
{
    return surname;
}

QString UserAccount::getAddress() const
{
    return address;
}

QString UserAccount::getPassportNumber() const
{
    return passport_number;
}

QString UserAccount::getPassportExpirationDate() const
{
    return passport_expiration_date;
}

QString UserAccount::getPassportIssuingCountry() const
{
    return passport_issuing_country;
}

QString UserAccount::getPassportIssuingDate() const
{
    return passport_issuing_date;
}

QString UserAccount::getPassportIssuingAuthority() const
{
    return passport_issuing_authority;
}

QString UserAccount::getPassportBirthPlace() const
{
    return passport_birth_place;
}

QString UserAccount::getPassportBirthDate() const
{
    return passport_birth_date;
}

QString UserAccount::getPassport() const
{
    return passport_number + " " + passport_expiration_date + " " + passport_issuing_country + " " + passport_issuing_date + " " + passport_issuing_authority + " " + passport_birth_place + " " + passport_birth_date;
}

QByteArray UserAccount::getHashedPassword(const QString password)
{
    // TODO: change the hashing algorithm to the SM3 algorithm (https://en.wikipedia.org/wiki/SM3_(hash_function)) and implement the algorithm in C++. The algorithm is described in the link, which is used in the Chinese government and is considered to be secure.  `
    return QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
}

UserAccount::~UserAccount()
{
}
