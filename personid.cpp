#include "personid.h"
#include "tools.h"

PersonID::PersonID(std::string id) : personID(id)
{

}

PersonID::PersonID()
{
    personID = createRandomID(PERSON_ID_LEN);
}
