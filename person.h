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
   public:
      std::string getName();
      std::string getSurname();
      long getID();
      std::string getAddress();
      void setName(std::string name);
      void setSurname(std::string surname);
      void setID(long ID);
};

#endif
