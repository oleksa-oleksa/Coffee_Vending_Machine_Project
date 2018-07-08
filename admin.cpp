// Created by Oleksandra Baga
#include "admin.h"
#include "card.h"
#include "account.h"
#include "cardstatus.h"
#include <string>
#include "QDebug"


Admin::Admin() {

}

Admin::Admin(Person *activeAdminPerson) {
    this->setID(activeAdminPerson->getID());
    this->setName(activeAdminPerson->getName());
    this->setSurname(activeAdminPerson->getSurname());
    this->setAddress(activeAdminPerson->getAddress());
    this->setEmployed(activeAdminPerson->getEmployed());
    this->setAdmin(activeAdminPerson->getAdmin());
    this->setStaff(activeAdminPerson->getStaff());
}



void Admin::cancelPersonCreation(Person *newPerson) {
    delete newPerson;

}

void Admin::cancelBankAccountCreation(BankAccount *newBankAccount) {
    delete newBankAccount;
}

void Admin::cancelAccountCreation(Account *newAccount) {
    delete newAccount;
}

void Admin::cancelCardCreation(Card *newCard) {
    delete newCard;
}


void Admin::addPerson(Person *newPerson, std::string newPersonName, std::string newPersonSurname,
                      std::string newPersonAddress, int isAdmin, int isStaff) {
    newPerson->setName(newPersonName);

    newPerson->setSurname(newPersonSurname);

    newPerson->setAddress(newPersonAddress);

    newPerson->setEmployed(true);

    newPerson->setAdmin(isAdmin);

    newPerson->setStaff(isStaff);

    Person::AllEmployee.push_back(*newPerson);

    qDebug() << "ADMIN: New Person added into AllEmployee";
}

void Admin::addBankAccount(BankAccount *newBankAccount, int taxClass) {
        newBankAccount->setAccountID(newAccount->getAccountID());

        newBankAccount->setTaxClass(taxClass);
        BankAccount::AllBankAccounts.push_back(*newBankAccount);

        qDebug() << "ADMIN: New depending Bank Account added into AllBankAccounts";
}

void Admin::addAccount(Account *newAccount) {
        //  accountID, credit and state are predefined by constructor

        Person &lastPerson = Person::AllEmployee.back();
        newAccount->setOwner(&lastPerson);

        BankAccount &lastBankAccount = BankAccount::AllBankAccounts.back();
        newAccount->setBankAccount(&lastBankAccount);

        Account::AllAccounts.push_back(*newAccount);
        Account &lastAccount = Account::AllAccounts.back();
        //delete newAccount; newAccount = NULL;

        lastAccount.setBankAccount(&lastBankAccount);
        lastBankAccount.setAccount(&Account::AllAccounts.back());
        qDebug() << "New depending Account added into AllAccounts";
}

void Admin::addCard(Card *newCard) {
        // CardID and CardStatus are predefined by constructor

        Card::AllCards.push_back(*newCard);

        Account &lastAccount = Account::AllAccounts.back();

        //delete newCard; newCard = NULL;

        Card::AllCards.back().setAccount(&lastAccount);
        qDebug() << "New depending Card added into AllAccounts";
}
