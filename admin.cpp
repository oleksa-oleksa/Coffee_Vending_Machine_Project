// Created by Oleksandra Baga
#include "admin.h"
#include "card.h"
#include "account.h"
#include "cardstatus.h"

Admin::Admin()
{

}

Admin::Admin(Person *activeAdminPerson)
{
    this->setID(activeAdminPerson->getID());
    this->setName(activeAdminPerson->getName());
    this->setSurname(activeAdminPerson->getSurname());
    this->setAddress(activeAdminPerson->getAddress());
    this->setEmployed(activeAdminPerson->getEmployed());
    this->setAdmin(activeAdminPerson->getAdmin());
    this->setStaff(activeAdminPerson->getStaff());
}


bool addEmployee()
{

}


Person *Admin::instantiateNewPerson(Person *newPerson)
{
    if (!newPerson) {
        newPerson = new Person();
    }

    return newPerson;
}

BankAccount *Admin::instantiateNewBankAccount(BankAccount *newBankAccount)
{

    if (!newBankAccount) {
        newBankAccount = new BankAccount();
    }

    return newBankAccount;
}

Account *Admin::instantiateNewAccount(Account *newAccount)
{

    if (!newAccount) {
        newAccount = new Account();
    }
    return newAccount;
}

Card *Admin::instantiateNewCard(Card *newCard)
{
    if (!newCard) {
        newCard = new Card();
    }
    return newCard;
}


void Admin::cancelPersonCreation(Person *newPerson)
{
    delete newPerson;
}

void Admin::cancelBankAccountCreation(BankAccount *newBankAccount)
{
    delete newBankAccount;
}

void Admin::cancelAccountCreation(Account *newAccount)
{
    delete newAccount;
}

void Admin::cancelCardCreation(Card *newCard)
{
    delete newCard;
}
