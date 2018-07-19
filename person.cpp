// Created by Oleksandra Baga
#include <iostream>
#include <QtDebug>
#include "person.h"
#include "tools.h"

std::vector<Person>Person::AllEmployee = std::vector<Person>();

Person::Person(const Person &other) : name(other.name), surname(other.surname), address(other.address),
    isAdmin(other.isAdmin), isStaff(other.isStaff), isEmployed(other.isEmployed), personID(other.personID)
{

}


Person *Person::createGlobal(std::string name, std::string surname, std::string address, bool isEmployed, bool isAdmin, bool isStaff)
{
    Person::AllEmployee.push_back(Person());
    Person *p = &Person::AllEmployee.back();

    p->setName(name);
    p->setSurname(surname);
    p->setAddress(address);

    p->setEmployed(isEmployed);
    p->setAdmin(isAdmin);
    p->setStaff(isStaff);
    return p;
}

// Default constructor is necessary b/c other is defined
// Effectively it's a default constructor
Person::Person() : personID() {
    isEmployed = true;
    isAdmin = false;
    isStaff = false;
}

// This constructor assumes that it receives a valid query
// pointing at some row of data from Person table
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

std::string const & Person::getName() const {
    return name;
}

std::string const & Person::getSurname() const {
    return surname;
}

std::string const & Person::getAddress() const {
    return address;
}

PersonID Person::getID() const {
    return personID;
}

void Person::setName(std::string name) {
    if (name == "") {
        qDebug() << "Name is empty";
        name = "NO_NAME";
    }
    this->name = name;
    qDebug() << "Name is set: " << this->name.c_str();
}

void Person::setSurname(std::string surname) {
    if (surname == "") {
        qDebug() << "Surname is empty";
        surname = "NO_SURNAME";
    }
    this->surname = surname;
    qDebug() << "Surname is set: " << this->surname.c_str();
}

void Person::setAddress(std::string address) {
    if (address == "") {
        qDebug() << "Address is empty";
        address = "NOT_EXISITING";
    }
    this->address = address;
    qDebug() << "Address is set: " << this->address.c_str();
}

void Person::setID(PersonID personID) {
    this->personID = personID;
}

bool Person::getEmployed() {
    return isEmployed;
}

void Person::setEmployed(bool isEmployed) {
    this->isEmployed = isEmployed;
    qDebug() << "Employed flag is set: " << this->isEmployed;
}

bool Person ::getAdmin() {
    return isAdmin;
}

void Person::setAdmin(bool isAdmin) {
    this->isAdmin = isAdmin;
    qDebug() << "Admin flag is set: " << this->isAdmin;
}

bool Person::getStaff() {
    return isStaff;
}

void Person::setStaff(bool isStaff) {
    this->isStaff = isStaff;
    qDebug() << "Staff flag is set: " << this->isStaff;
}
