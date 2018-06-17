#include "personid.h"
#include "tools.h"

#define PERSON_ID_LEN 5

PersonID::PersonID()
{
    personID = createRandomID(PERSON_ID_LEN);
}
