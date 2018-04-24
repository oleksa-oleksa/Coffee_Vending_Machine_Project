#ifndef ACCOUNTSTATUS_H
#define ACCOUNTSTATUS_H


class AccountStatus
{
public:
    AccountStatus();
    ~AccountStatus();

private:
    enum {
        ACTIVE_OK,
        BLOCKED_UNPAID,
        DEACTIVATED_OLD
    };
};

#endif // ACCOUNTSTATUS_H
