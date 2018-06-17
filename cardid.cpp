#include "cardid.h"
#include "tools.h"
#include <iostream>
#define CARD_ID_LEN 16

CardID::CardID()
{
    cardID = createRandomID(CARD_ID_LEN);
}

