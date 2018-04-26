#ifndef SERVICEROUTINE_H
#define SERVICEROUTINE_H


class ServiceRoutine
{
public:
    ServiceRoutine();
    ~ServiceRoutine();

private:
    boolean isCleanedStorageContainer = false;
    boolean isCleanedModules = false;
    boolean isCleanedGarbageBin = false;
};

#endif // SERVICEROUTINE_H
