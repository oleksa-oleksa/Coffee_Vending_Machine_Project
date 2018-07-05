#include "person.h"
#include "account.h"
#include "bankaccount.h"
#include "userchoice.h"
#include "card.h"
#include "interactionunit.h"

InteractionUnit iunit;

Person *activePerson = NULL;
Account *activeAccount = NULL;
BankAccount *bankAccount = NULL;

UserChoice *activeUserChoice = NULL;
Card *card = NULL;
