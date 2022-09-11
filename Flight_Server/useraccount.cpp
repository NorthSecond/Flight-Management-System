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

bool UserAccount::WriteToDB(QSqlDatabase db)
{
    // TODO: 和数据库统一格式
    if(!db.isOpen())
    {
        return false;
    }
    QSqlQuery query(db);
    query.prepare("INSERT INTO user_account (username, password_hash, phone, name, surname, address, passport_number, passport_expiration_date, passport_issuing_country, passport_issuing_date, passport_issuing_authority, passport_birth_place, passport_birth_date, email) VALUES (:username, :password_hash, :phone, :name, :surname, :address, :passport_number, :passport_expiration_date, :passport_issuing_country, :passport_issuing_date, :passport_issuing_authority, :passport_birth_place, :passport_birth_date, :email)");
    query.bindValue(":username", username);
    query.bindValue(":password_hash", password_hash);
    query.bindValue(":phone", phone);
    query.bindValue(":name", name);
    query.bindValue(":surname", surname);
    query.bindValue(":address", address);
    query.bindValue(":passport_number", passport_number);
    query.bindValue(":passport_expiration_date", passport_expiration_date);
    query.bindValue(":passport_issuing_country", passport_issuing_country);
    query.bindValue(":passport_issuing_date", passport_issuing_date);
    query.bindValue(":passport_issuing_authority", passport_issuing_authority);
    query.bindValue(":passport_birth_place", passport_birth_place);
    query.bindValue(":passport_birth_date", passport_birth_date);
    query.bindValue(":email", email);
    return query.exec();
}

bool UserAccount::writeToLog(QString log_info){
    QFile file("./logs/account.log");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        return false;
    }
    QTextStream out(&file);
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << log_info << ":\n\t";
    out << log_info << Qt::endl;
    return true;
}
