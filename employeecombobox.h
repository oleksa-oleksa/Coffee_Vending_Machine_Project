#ifndef EMPLOYEECOMBOBOX_H
#define EMPLOYEECOMBOBOX_H

#include <qcombobox.h>

class EmployeeComboBox : public QComboBox
{
    Q_OBJECT

private:
    void populateContent();

public:
    void resetContent();

public:
    EmployeeComboBox(QWidget *w);
};

#endif // EMPLOYEECOMBOBOX_H
