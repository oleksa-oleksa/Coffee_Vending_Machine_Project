// Created by Oleksandra Baga
#include "cardid.h"
#include "tools.h"
#include <iostream>

CardID::CardID(std::string id) : cardID(id)
{

}

CardID::CardID()
{
    cardID = std::string("5100") + createRandomID(CARD_ID_LEN);
}

QString CardID::toQstring()
{
  return QString::fromUtf8(cardID.c_str());
}
