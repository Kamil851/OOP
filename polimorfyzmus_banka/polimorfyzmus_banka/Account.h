#pragma once
#include "Account.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Client.h"

class Account {
private:
    int number;
    double balance;
    double interestRate;
    Client owner;

public:
    Account(int n, Client* o);
    Account(int n, Client* o, double ir);
    virtual bool CanWithdraw(double a);
    double GetBalance() const { return balance; }
};

#endif // ACCOUNT_H
