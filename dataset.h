#ifndef DATASET_H
#define DATASET_H
#include "account.h"

class Dataset
{
public:
    Dataset();
    ~Dataset();
    void addBill(long cardID, double price);

private:
    long dbID;
    Account *account;
};

#endif // DATASET_H
