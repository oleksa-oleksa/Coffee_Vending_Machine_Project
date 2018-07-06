#include "admintest.h"

void AdminTest::testAddPerson()
{
    Admin *admin = new Admin();

    qDebug() << "01: a Admin add a new Admin";
    Person *person1 = new Person();

    admin->addPerson(person1, "Brice", "Dorsey", "BerlinerStrasse 20", true, false);

    qDebug() << "02: a Admin add a new Person";
    Person *person2 = new Person();
    admin->addPerson(person2, "Long", "Dje", "kudamm 20", false, true);
}

void AdminTest::testAddBankAccount()
{

}
