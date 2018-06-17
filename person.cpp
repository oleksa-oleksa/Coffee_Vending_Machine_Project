#include <iostream>
#include <QtDebug>
#include "person.h"
#include "tools.h"

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
    qDebug() << "ID is: " << id;
    return personID;
}

void Person::setName(std::string name)
{
    if ( name == "" )
        qDebug() << "Name cannot be an empty String!";
    else
        qDebug() << "Name is set: " << name.c_str();
        this->name = name;
}

void Person::setSurname(std::string surname)
{
    if ( surname == "" )
        qDebug() << "Name cannot be an empty String!";
    else
        qDebug() << "Surname is set: " << surname.c_str();
        this->surname = surname;
}

void Person::setID(PersonID personID)
{
    qDebug() << "Name is set: " << name.c_str();
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

bool Person::getStaff()
{
    qDebug() << "Staff flag is: " << isStaff;
    return isStaff;
}

void Person::setStaff(bool isStaff)
{
    this->isStaff = isStaff;
    qDebug() << "Staff flag is set: " << isStaff;
}
