#include <vector>
#include "defaultcoffeemachinewithoutdb.h"
#include "person.h"
#include "card.h"
#include "bankaccount.h"
#include "account.h"

void DefaultCoffeeMachineWithoutDb::createRecords()
{
    // Employees

    Person *p;
    Account *a;
    Card *c;
    BankAccount *ba;

    Person::AllEmployee.reserve(16);
    Account::AllAccounts.reserve(16);
    Card::AllCards.reserve(16);
    BankAccount::AllBankAccounts.reserve(16);

    p = Person::createGlobal("Oleksandra", "Baga", "Beuthstr. 14, 12163 Berlin", 1, 1, 1);
    ba = BankAccount::createGlobal(1);
    a = Account::createGlobal(p, ba, 0.0, ACTIVE_OK);
    c = Card::createGlobal(a, ACTIVE);

    p = Person::createGlobal("Christian", "Spiegel", "Kaiserin-Augusta-Allee 77, 10589 Berlin", 1, 0, 0);
    ba = BankAccount::createGlobal(1);
    a = Account::createGlobal(p, ba, 0.0, ACTIVE_OK);
    c = Card::createGlobal(a, ACTIVE);

    p = Person::createGlobal("Daniel", "Hoffmann", "Beusselstr. 22, 10567 Berlin", 1, 0, 0);
    ba = BankAccount::createGlobal(1);
    a = Account::createGlobal(p, ba, 0.0, ACTIVE_OK);
    c = Card::createGlobal(a, ACTIVE);

    p = Person::createGlobal("Katharina", "Falten", "Klarenbachstr. 43, 10270 Berlin", 1, 1, 0);
    ba = BankAccount::createGlobal(1);
    a = Account::createGlobal(p, ba, 0.0, ACTIVE_OK);
    c = Card::createGlobal(a, ACTIVE);

    p = Person::createGlobal("Mathias", "Schulz", "Quedlinburger Str. 54, 10340 Berlin", 1, 0, 1);
    ba = BankAccount::createGlobal(1);
    a = Account::createGlobal(p, ba, 0.0, ACTIVE_OK);
    c = Card::createGlobal(a, ACTIVE);

    p = Person::createGlobal("Tobias", "Testermann", "Neues Ufer 18, 10490 Berlin", 0, 1, 1);
    ba = BankAccount::createGlobal(1);
    a = Account::createGlobal(p, ba, 0.0, ACTIVE_OK);
    c = Card::createGlobal(a, ACTIVE);

}
