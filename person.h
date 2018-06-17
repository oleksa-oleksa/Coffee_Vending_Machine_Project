#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "personid.h"

class Person
{
   private:
      PersonID personID;
      std::string name;
      std::string surname;
      long id;
      std::string address;


      // a person should be emploeyd at the company to be able to buy a drink
      // if person will be fired, the all flags must be reseted.
      bool isEmployed;

      // It is allowed to be an admin and a staff at the same time
      // a person could be an admin
      bool isAdmin;

      //a person could provide service functions
      bool isStaff;
   public:
      std::string const & getName() const;
      std::string const & getSurname() const;
      std::string const & getAddress() const;
      PersonID getID() const;
      void setName(std::string name);
      void setSurname(std::string surname);
      void setID(PersonID ID);
      bool getEmployed();
      void setEmployed(bool isEmployed);
      bool getAdmin();
      void setAdmin(bool isAdmin);
      bool getStaff();
      void setStaff(bool isStaff);
};

#endif
