// Created by Oleksandra Baga
#include "defaultcoffeemachine.h"
#include <QFile>
#include "database.h"
#include "tools.h"
#include "bankaccount.h"

// Database for all Records: Person, Account, BankAccount, Card
Database coffeeMachine_DB;

DefaultCoffeeMachine::DefaultCoffeeMachine()
{

}


bool DefaultCoffeeMachine::createDefaulDB(std::string db_name)
{
    bool ret = true;

    coffeeMachine_DB.openDB(db_name);
    using namespace std;

    // Tables creation
    ret = ret && assert(coffeeMachine_DB.createPersonTable() == true, "Failed default Person table creation");
    ret = ret && assert(coffeeMachine_DB.createBankAccountTable() == true, "Failed default Bank Account table creation");
    ret = ret && assert(coffeeMachine_DB.createAccountTable() == true, "Failed default Account table creation");
    ret = ret && assert(coffeeMachine_DB.createCardTable() == true, "Failed default Card table creation");

    // Default table inserts:
    // 1. Person will be inserted with the random ID, that is assumed to be always correct
    // 2. Bank Account will be inserted with random IBAN, that is assumed to be always correct
    // 3. Person and Bank Account Tables will be linked via foreign key when they will be read from DB
    // 4. Account will be created with the random ID
    // 5. Account will be linked to other tables when rows will be readed from DB for the first time
    // 6. Card ID will be created with random ID and linked immediately (Precondition: Other Tables created and loaded into programm memory)

    // Default Employees:
    // 2 Admin
    // 2 Staff
    // 2 Employees
    // All employees can buy drink if their account is not blocked
    // 1 unemloyed person for test purpose
    ret = ret && assert(coffeeMachine_DB.insertPerson("Oleksandra", "Baga", "Beuthstr. 14, 12163 Berlin", 1, 1, 0) == true, "Insert Person01 failed");
    ret = ret && assert(coffeeMachine_DB.insertPerson("Christian", "Spiegel", "Kaiserin-Augusta-Allee 77, 10589 Berlin", 1, 0, 0) == true, "Insert Person02 failed");
    ret = ret && assert(coffeeMachine_DB.insertPerson("Daniel", "Hoffmann", "Beusselstr. 22, 10567 Berlin", 1, 0, 0) == true, "Insert Person03 failed");
    ret = ret && assert(coffeeMachine_DB.insertPerson("Katharina", "Falten", "Klarenbachstr. 43, 10270 Berlin", 1, 0, 1) == true, "Insert Person04 failed");
    ret = ret && assert(coffeeMachine_DB.insertPerson("Mathias", "Schulz", "Quedlinburger Str. 54, 10340 Berlin", 1, 1, 1) == true, "Insert Person05 failed");
    ret = ret && assert(coffeeMachine_DB.insertPerson("Tobias", "Testermann", "Neues Ufer 18, 10490 Berlin", 0, 1, 1) == true, "Insert Person06 failed");

    // Depended Tables
    // 1. Bank Account
    // Account ID (foreign key) created based on Person Table
    // Primary Key will be creted by insert()
    People people;
    ret = ret && assert(coffeeMachine_DB.loadPeople(people) == true, "Load Persons failed during insert into BankAccount table");

    for (size_t i = 0; i < people.size(); i++)
    {
        std::string tmp_accID = std::string("ACC") + createRandomID(ACCOUNT_ID_LEN);
        QString str = QString::fromUtf8(tmp_accID.c_str());
        ret = ret && assert(coffeeMachine_DB.insertBankAccount(str, 1) == true, "Insert default BankAccounts failed");
    }

    // 2. Account
    // AccountID was already created by creation of Bank Account
    BAccounts ba;
    ret = ret && assert(coffeeMachine_DB.loadBankAccounts(ba) == true, "Load BankAccount failed during insert into Account table");

    // Bank Accounts and Account are always corresponding to the amount of people
    // this is the solution for this particular issue
    for (size_t i = 0; i < people.size(); i++)
    {
        // Obtaining Primary Key
        AccountID tmp_id1 = ba[i].getAccountID();
        QString q_aid = tmp_id1.toQstring();

        // Obtaining Foreign Keys
        BankAccountID tmp_id2 = ba[i].getIBAN();
        QString q_baid = tmp_id2.toQstring();

        PersonID tmp_id3 = people[i].getID();
        QString q_pid = tmp_id3.toQstring();

        ret = ret && assert(coffeeMachine_DB.insertAccount(q_aid, q_pid, q_baid, 0.0, 0) == true, "Insert default Accounts failed");
    }

    // 3. Card
    Accounts a;
    ret = ret && assert(coffeeMachine_DB.loadAccounts(a) == true, "Load Accounts failed during insert into Card table");

    for (size_t i = 0; i < a.size(); i++)
    {
        AccountID tmp_id1 = a[i].getAccountID();
        QString q_aid = tmp_id1.toQstring();

        ret = ret && assert(coffeeMachine_DB.insertCard(0, q_aid) == true, "Insert default Cards failed");
    }

    // When records were inserted in all tables
    // they should be loaded into memory with restoreDefaultDB()
    // and then they could be accessed via corresponding classes and methods.

    coffeeMachine_DB.closeDatabase();
    return ret;
}

bool DefaultCoffeeMachine::restoreDefaultDB(std::string db_name)
{
    bool ret = false;

    coffeeMachine_DB.openDB(db_name);

    assert(coffeeMachine_DB.loadPeople(Person::AllEmployee) == true, "Load global Persons failed");
    assert(coffeeMachine_DB.loadBankAccounts(BankAccount::AllBankAccounts) == true, "Load global BankAccounts failed");
    assert(coffeeMachine_DB.loadAccounts(Account::AllAccounts) == true, "Load global Accounts failed");
    assert(coffeeMachine_DB.loadCards(Card::AllCards) == true, "Load global Cards failed");

    coffeeMachine_DB.closeDatabase();
    return ret;
}
