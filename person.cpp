#include <iostream>
#include <QtDebug>
#include "person.h"

std::string const & Person::getName() const
{
    qDebug() << "Name is: " << name;
    return name;
}

std::string const & Person::getSurname() const
{
    qDebug() << "Surname is: " << name;
    return surname;
}

std::string const & Person::getAddress() const
{
    qDebug() << "Adress is: " << address;
    return address;
}

long Person::getID() const
{
    qDebug() << "ID is: " << id;
    return id;
}

void Person::setName(std::string name)
{
    if ( name == "" )
        qDebug() << "Name cannot be an empty String!";
    else
        qDebug() << "Name is set: " << name;
        this->name = name;
}

void Person::setSurname(std::string surname)
{
    if ( surname == "" )
        qDebug() << "Name cannot be an empty String!";
    else
        qDebug() << "Surname is set: " << surname;
        this->surname = surname;
}

void Person::setID(long ID)
{
    /*
         TODO Check, if the ID is in Range of valid IDs
         we need to decide a valid range
    */
    qDebug() << "Name is set: " << name;
    this->id = ID;
}

bool Person::getEmployed()
{
    qDebug() << "Employed flag is: " << isEmployed;
    return isEmployed;
}

void Person::setEmployed(bool isEmployed)
{
    this->isEmployed = isEmployed;
    qDebug() << "Employed flag is set: " << isEmployed;
}

bool Person ::getAdmin()
{
    qDebug() << "Admin flag is: " << isAdmin;
    return isAdmin;
}

void Person::setAdmin(bool isAdmin)
{
    this->isAdmin = isAdmin;
    qDebug() << "Admin flag is set: " << isAdmin;
}

void Person::getStaff()
{
    qDebug() << "Staff flag is: " << isStaff;
    return isStaff;
}

set Person::setStaff(bool isStaff)
{
    this->isStaff = isStaff;
    qDebug() << "Staff flag is set: " << isStaff;
}
