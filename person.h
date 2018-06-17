#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
   private:
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
      long getID() const;
      void setName(std::string name);
      void setSurname(std::string surname);
      void setID(long ID);
      bool getEmployed();
      void setEmployed();
      bool getAdmin();
      void setAdmin();
      bool getStaff();
      void setStaff();
};

#endif
