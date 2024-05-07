#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class AbstractAccount {
public:
    AbstractAccount();
    virtual ~AbstractAccount();
    virtual bool CanWithdraw(double a) = 0;
};

class Client {
private:
    int id;
    std::string name;
public:
    Client(int id, const std::string& name);
    ~Client();
};

class Account : public AbstractAccount {
private:
    int number;
    double balance;
    double interestRate;
    Client* owner;

public:
    Account(int n, Client* o);
    Account(int n, Client* o, double ir);
    virtual ~Account();
    int GetNumber();
    double GetBalance();
    double GetInterestRate();
    Client* GetOwner();
    virtual bool CanWithdraw(double a) override;
    void Deposit(double a);
    bool Withdraw(double a);
    void AddInterest();
};

#endif // ACCOUNT_H
