#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "client.h"

class Account {
private:
    int number;
    double interestRate;
    Client* owner;

protected:
    double balance;

public:
    Account(int n, Client* o);
    Account(int n, Client* o, double ir);

    int GetNumber();
    double GetBalance();
    double GetInterestRate();
    Client* GetOwner();
    bool CanWithdraw(double a);

    void Deposit(double a);
    bool Withdraw(double a);
    void AddInterest();
};

#endif // ACCOUNT_H
