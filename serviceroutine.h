#ifndef SERVICEROUTINE_H
#define SERVICEROUTINE_H


class ServiceRoutine
{
public:
    ServiceRoutine();
    ~ServiceRoutine();

private:
    bool isCleanedStorageContainer = false;
    bool isCleanedModules = false;
    bool isCleanedGarbageBin = false;
};

#endif // SERVICEROUTINE_H
