#ifndef PERSONID_H
#define PERSONID_H
#include <iostream>

#define PERSON_ID_LEN 5

class PersonID
{
    friend class Database;
    private:
        std::string personID;


    public:
        PersonID(std::string id);
        PersonID();
};

#endif // PERSONID_H
