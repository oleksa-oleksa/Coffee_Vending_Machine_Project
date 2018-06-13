#include <iostream>

#include "person.h"

std::string const & Person::getName() const
{
    return name;
}

std::string const & Person::getSurname() const
{
    return surname;
}

std::string const & Person::getAddress() const
{
    return address;
}

long Person::getID() const
{
    return id;
}

void Person::setName(std::string name)
{
    if ( name == "" )
        std::cerr << "Name cannot be an empty String" << std::endl;
    else
        this->name = name;
}

void Person::setSurname(std::string surname)
{
    if ( surname == "" )
        std::cerr << "Surname cannot be an empty String" << std::endl;
    else
        this->surname = surname;
}

void Person::setID(long ID)
{
    /*
         TODO Check, if the ID is in Range of valid IDs
         we need to decide a valid range
    */
    this->id = ID;
}

