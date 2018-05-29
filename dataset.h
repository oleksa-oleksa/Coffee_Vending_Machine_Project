#ifndef DATASET_H
#define DATASET_H
#include "account.h"

class Dataset
{
    private:
        long dbID;
        Account *account;

    public:
        Dataset();
        ~Dataset();
        void addBill();
};

#endif // DATASET_H
