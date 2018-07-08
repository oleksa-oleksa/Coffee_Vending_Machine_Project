// Created by Oleksandra Baga
#include <iostream>
#include <tools.h>
#include <QDebug>

/* Created a random ID of fixed lenght
   The ID entyties is used for DB as:
   AccountID
   PersonID
   CardID
   BankAccountID
*/
std::string createRandomID(int lenght) {
    std::string newID(lenght, '0');
    static const char alphanum[] =
            "0123456789"
            "BBERDED";

        for (int i = 0; i < lenght; ++i) {
            newID[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        return newID;
}

bool assert(bool flag, const char *error_msg) {
  if (!flag) {
    qDebug() << error_msg;
    return false;
  }
  return true;
}
