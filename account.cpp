// Created by Oleksandra Baga
#include "account.h"
#include "personid.h"
#include "person.h"
#include <QtDebug>

const float CREDIT_LIMIT = 5.0;

std::vector<Account>Account::AllAccounts = std::vector<Account>();

Account *Account::createGlobal(Person *owner, BankAccount *ba,double credit, AccountStatus state)
{
    Account::AllAccounts.push_back(Account());
    Account *pa = &Account::AllAccounts.back();

    pa->setBankAccount(ba);
    pa->setOwner(owner);
    pa->setAccountCredit(credit);
    pa->setAccountStatus(state);

    ba->setAccount(pa);

    return pa;
}

Account::Account() : accountID() {
    credit = 0.0;
    state = ACTIVE_OK;
    owner = NULL;
    ba = NULL;
}

// This constructor assumes that it receives a valid query
// pointing at some row of data from Account table
Account::Account(QSqlRecord &query) {
    using namespace std;

    QString q_aid = query.value(0).toString();
    QString q_pid = query.value(1).toString();
    QString q_baid = query.value(2).toString();
    credit = query.value(3).toDouble();
    state = (AccountStatus)query.value(4).toInt();;

    accountID = AccountID(q_aid.toUtf8().constData());

    PersonID personID = PersonID(q_pid.toUtf8().constData());
    linkOwner(personID);
    BankAccountID iban = BankAccountID(q_baid.toUtf8().constData());
    linkBankAccount(iban);
}

Account::Account(Person *Employee, BankAccount *Ba) {
    credit = 0.0;
    state = ACTIVE_OK;
    owner = Employee;
    ba = Ba;
}

AccountStatus Account::getAccountStatus() {
    QString str = printAccountStatus();
    qDebug() << "ACCOUNT GETTER: Account status is: " << str;
    return state;
}


void Account::setAccountStatus(AccountStatus state) {
    this->state = state;
    QString str = printAccountStatus();
}

bool Account::checkCreditLimit(double amount) {
    // Not active account case
    if (getAccountStatus() != ACTIVE_OK) {
        qDebug() << "Account is not active, purchase canceled...";
        return false;
    }

    // Check Limit case
    if (credit >= CREDIT_LIMIT) {
        qDebug() << "Limit: " << CREDIT_LIMIT  << " is reached. Oops!";
        blockAccount();
        return false;
    }

    if ((credit + amount) >= CREDIT_LIMIT) {
        qDebug() << "You can not buy this drink, the limit will be exceeded!";
        double tmp = CREDIT_LIMIT -  getAccountCredit();
        qDebug() << tmp << "€ is available for drink purchase!";
        return false;
    }
    qDebug() << "Credit is OK, drink can be purchased!";
    return true;
}


double Account::getAccountCredit()  const {
    return credit;
}

Person *Account::getOwner()  const {
    return owner;
}

void Account::setOwner(Person *owner) {
    this->owner = owner;
}

BankAccount *Account::getBankAccount()  const {
    return ba;
}

void Account::setAccountID(AccountID accountID) {
   this->accountID = accountID;
}

AccountID Account::getAccountID() const {
    return accountID;
}

void Account::setBankAccount(BankAccount *ba) {
    this->ba = ba;
}

// Simple setter
void Account::setAccountCredit(double credit) {
    this->credit = credit;
    qDebug() << "SETTER: credit is set: " << credit;

}

// increases credit if account is not blocked and limit will be not exceeded
bool Account::addCredit(double amount) {
    if (getAccountStatus() != ACTIVE_OK) {
        qDebug() << "Account is not active, purchase canceled...";
        return false;
    }

    // if credit limit is not reached, user can buy a new drink
    if (checkCreditLimit(amount)) {
        // Obtaining actual credit
        double tmp_cr = getAccountCredit();
        // increasing
        tmp_cr += amount;
        // setting
        setAccountCredit(tmp_cr);

        qDebug() << "Credit: " << amount  << " added to the card";
        qDebug() << "New credit: " <<  credit;
        return true;
    }
    else {
        qDebug() << "Payment attemt is canceled...";
        return false;
    }
}

void Account::activateAccount() {
    setAccountStatus(ACTIVE_OK);
    qDebug() << "ACTIVATE: Account is activated";
}

void Account::deactivateAccount() {
    setAccountStatus(DEACTIVATED_OLD);
    qDebug() << "DEACTIVATE: Account is deactivated";
}

void Account::blockAccount() {
    setAccountStatus(BLOCKED_UNPAID);
    qDebug() << "BLOCK: Account is blocked";
}

bool Account::linkOwner(PersonID personID) {
    bool ret = false;

    for (size_t i = 0; i < Person::AllEmployee.size(); i++) {
       if (Person::AllEmployee[i].getID().toQstring() == personID.toQstring()) {
          setOwner(&Person::AllEmployee[i]);
          qDebug() << "LINK TO ACCOUNT: OWNER is set to PersonID:" << Person::AllEmployee[i].getID().toQstring();
          ret = true;
       }
    }
    return ret;
}

bool Account::linkBankAccount(BankAccountID iban) {
    bool ret = false;

    for (size_t i = 0; i < BankAccount::AllBankAccounts.size(); i++) {
       if (BankAccount::AllBankAccounts[i].getIBAN().toQstring() == iban.toQstring()) {
          setBankAccount(&BankAccount::AllBankAccounts[i]);
          qDebug() << "LINK TO ACCOUNT: BANK ACCOUNT is set to IBAN:" << BankAccount::AllBankAccounts[i].getIBAN().toQstring();
          ret = true;
       }
    }
    if (!ret) {
        qDebug() << "Bank Account was not linked! No corresponding record in array!";
    }
    return ret;
}

QString Account::printAccountStatus() {
    QString str;
    switch (this->state) {
    case ACTIVE_OK:
            str = "ACTIVE_OK";
            return str;
    case BLOCKED_UNPAID:
            str = "BLOCKED_UNPAID";
            return str;
    case DEACTIVATED_OLD:
            str = "DEACTIVATED_OLD";
            return str;
    default:
        break;
    }
}

