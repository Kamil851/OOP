#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "client.h"

class Account {
private:
    static int objectsCount;
    int number;
    double balance;
    double interestRate;
    Client* owner;

public:
    static int GetObjectsCount();

    Account(int n, Client* o);
    Account(int n, Client* o, double ir);
    virtual ~Account();

    int GetNumber() const;
    double GetBalance() const;
    double GetInterestRate() const;
    Client* GetOwner() const;

    bool CanWithdraw(double a) const;
    void Deposit(double a);
    bool Withdraw(double a);
    void AddInterest();
};

#endif // ACCOUNT_H
