// Created by Oleksandra Baga
#include <iostream>
#include <QtDebug>
#include "person.h"
#include "tools.h"

std::vector<Person>Person::AllEmployee = std::vector<Person>();

// Default constructor is necessary b/c other is defined
// Effectively it's a default constructor
Person::Person()
{
}

// This constructor assumes that it receives a valid query
// pointing at some row of data from Person table
// Assumed row positions are
Person::Person(QSqlRecord &query)
{
    using namespace std;

    QString q_pid = query.value(0).toString();
    QString q_name = query.value(1).toString();
    QString q_surname = query.value(2).toString();
    QString q_address = query.value(3).toString();

    // can also be converted to int with toInt()
    isEmployed = query.value(4).toBool();
    isAdmin = query.value(5).toBool();
    isStaff = query.value(6).toBool();

    // qs.toUtf8().constData() is a way to convert QString to std::string
    personID = PersonID(q_pid.toUtf8().constData());
    name = q_name.toUtf8().constData();
    surname = q_surname.toUtf8().constData();
    address = q_address.toUtf8().constData();
}


std::string const & Person::getName() const
{
    qDebug() << "Name is: " << name.c_str();
    return name;
}

std::string const & Person::getSurname() const
{
    qDebug() << "Surname is: " << name.c_str();
    return surname;
}

std::string const & Person::getAddress() const
{
    qDebug() << "Adress is: " << address.c_str();
    return address;
}

PersonID Person::getID() const
{
    return personID;
}

void Person::setName(std::string name)
{
    if ( name == "" )
        qDebug() << "Name cannot be an empty String!";
    else
        this->name = name;
        qDebug() << "Name is set: " << this->name.c_str();
}

void Person::setSurname(std::string surname)
{
    if ( surname == "" )
        qDebug() << "Name cannot be an empty String!";
    else
        this->surname = surname;
        qDebug() << "Surname is set: " << this->surname.c_str();
}

void Person::setID(PersonID personID)
{
    this->personID = personID;

}

bool Person::getEmployed()
{
    qDebug() << "Employed flag is: " << isEmployed;
    return isEmployed;
}

void Person::setEmployed(bool isEmployed)
{
    this->isEmployed = isEmployed;
    qDebug() << "Employed flag is set: " << this->isEmployed;
}

bool Person ::getAdmin()
{
    qDebug() << "Admin flag is: " << isAdmin;
    return isAdmin;
}

void Person::setAdmin(bool isAdmin)
{
    this->isAdmin = isAdmin;
    qDebug() << "Admin flag is set: " << this->isAdmin;
}

bool Person::getStaff()
{
    qDebug() << "Staff flag is: " << isStaff;
    return isStaff;
}

void Person::setStaff(bool isStaff)
{
    this->isStaff = isStaff;
    qDebug() << "Staff flag is set: " << this->isStaff;
}
