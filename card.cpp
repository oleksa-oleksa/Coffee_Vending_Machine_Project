// Created by Oleksandra Baga
#include "card.h"
#include <iostream>
#include "accountstatus.h"
#include "cardstatus.h"
#include "cardid.h"
#include <QtDebug>

std::vector<Card>Card::AllCards = std::vector<Card>();

Card::Card() : cardID() {
    cardStatus = ACTIVE;
}

Card::Card(Account *ac) {
    cardStatus = ACTIVE;
    account = ac;
}

Card::~Card() {

}

// This constructor assumes that it receives a valid query
// pointing at some row of data from Card table
Card::Card(QSqlRecord &query) {
    using namespace std;

    QString q_cid = query.value(0).toString();
    cardStatus = (CardStatus)query.value(1).toInt();
    QString q_aid = query.value(2).toString();

    cardID = CardID(q_cid.toUtf8().constData());
    AccountID accountID = AccountID(q_aid.toUtf8().constData());
    linkAccount(accountID);
}

CardID Card::getCardID() {
    return cardID;
}

void Card::setCardID(CardID newCardID) {
    cardID = newCardID;
    qDebug() << "Card ID is set";
}

CardStatus Card::getCardStatus() {
    QString str = printCardStatus();
    qDebug() << "CARD GETTER: Card status is: " << str;
    return cardStatus;

}

void Card::setCardStatus(CardStatus newStatus) {
    cardStatus = newStatus;
}

void Card::deactivateCard() {
    qDebug() << "DEACTIVATE: Card is deactivated";
    setCardStatus(DEACTIVATED);
}

void Card::activateCard() {
    qDebug() << "ACTIVATE: Card is activated";
    setCardStatus(ACTIVE);
}

Account *Card::getAccount() {
    return account;
}

void Card::setAccount(Account *newAccount) {
    account = newAccount;
}

bool Card::withdraw(double price) {
   if (!account->getOwner()->getEmployed()) {
       qDebug() << "Person is not employeed, payment is denied!";
       account->deactivateAccount();
       return false;
   }

   if (account->addCredit(price)) {
       qDebug() << "Credit added to card's account";
       return true;
   }
   else {
       qDebug() << "Error adding credit to card's account";
       return false;
   }
}

bool Card::linkAccount(AccountID accountID) {
    bool ret = false;

    for (size_t i = 0; i < Account::AllAccounts.size(); i++) {
       if (Account::AllAccounts[i].getAccountID().toQstring() == accountID.toQstring()) {
          setAccount(&Account::AllAccounts[i]);
          qDebug() << "LINK TO CARD: Account is set to AccountID:" << Account::AllAccounts[i].getAccountID().toQstring();
          ret = true;
       }
    }
    if (!ret) {
        qDebug() << "Account was not linked! No corresponding record in array!";
    }
    return ret;
}

QString Card::printCardStatus() {
    QString str;
    switch (cardStatus) {
    case ACTIVE:
            str = "ACTIVE";
            return str;
    case DEACTIVATED:
            str = "DEACTIVATED";
            return str;
    default:
        break;
    }
}
