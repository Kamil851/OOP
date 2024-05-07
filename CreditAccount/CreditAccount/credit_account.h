#pragma once
#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H

#include "account.h"

class CreditAccount : public Account {
private:
    double credit;

public:
    CreditAccount(int n, Client* o, double c);
    CreditAccount(int n, Client* o, double ir, double c);

    bool CanWithdraw(double a);
    bool Withdraw(double a);
};

#endif // CREDIT_ACCOUNT_H
