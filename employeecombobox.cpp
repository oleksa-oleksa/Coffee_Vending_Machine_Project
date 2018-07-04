#include <qstring.h>

#include "employeecombobox.h"
#include "person.h"
#include "card.h"

EmployeeComboBox::EmployeeComboBox(QWidget *w) : QComboBox(w)
{
    populateContent();
}

QString _q(const std::string s)
{
    return QString::fromUtf8(s.c_str());
}

void EmployeeComboBox::resetContent()
{
    clear();
    populateContent();
}

void EmployeeComboBox::populateContent()
{
    int i = 0;
    for (auto it = Card::AllCards.begin();
         it != Card::AllCards.end();
         ++it, ++i ) {

        Account *a = it->getAccount();
        if (!a) {
            continue;
        }
        Person *p = a->getOwner();

        QString item_text = _q(p->getName());
        item_text += " ";
        item_text += _q(p->getSurname());
        item_text += " (";
        item_text += p->getEmployed() ?
                    "employed" : "not employed";

        if (p->getStaff()) {
            item_text += ", staff";
        }

        if (p->getAdmin()) {
            item_text += ", admin";
        }

        item_text += ")";

        addItem(item_text, i);
    }

}
