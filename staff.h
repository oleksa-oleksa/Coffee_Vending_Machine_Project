#ifndef STAFF_H
#define STAFF_H

#include "person.h"
#include "serviceroutine.h"

class Staff : public Person
{
   private:
      ServiceRoutine SR;      
   public:
      bool startServiceRoutine();
};

#endif
