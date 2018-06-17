#include "personid.h"
#include "tools.h"

PersonID::PersonID()
{
    personID = createRandomID(PERSON_ID_LEN);
}
