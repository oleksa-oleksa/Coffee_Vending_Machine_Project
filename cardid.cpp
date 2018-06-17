#include "cardid.h"
#include "tools.h"
#include <iostream>

CardID::CardID()
{
    cardID = createRandomID(CARD_ID_LEN);
}

