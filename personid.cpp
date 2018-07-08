// Created by Oleksandra Baga
#include "personid.h"
#include "tools.h"

PersonID::PersonID(std::string id) : personID(id) {

}

PersonID::PersonID() {
    personID = createRandomID(PERSON_ID_LEN);
}

QString PersonID::toQstring() {
  return QString::fromUtf8(personID.c_str());
}
