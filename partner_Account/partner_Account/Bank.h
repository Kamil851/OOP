#pragma once
#ifndef BANK_H
#define BANK_H

#include "client.h"
#include "account.h"
#include "partner_account.h"

class Bank {
private:
    Client** clients;
    Account** accounts;
    int clientsCount;
    int accountsCount;
    int maxClients;
    int maxAccounts;

public:
    Bank(int c, int a);
    ~Bank();

    Client* GetClient(int c) const;
    Account* GetAccount(int n) const;

    Client* CreateClient(int c, std::string n);
    Account* CreateAccount(int n, Client* c);
    Account* CreateAccount(int n, Client* c, double ir);
    PartnerAccount* CreateAccount(int n, Client* c, Client* p, double ir);

    void AddInterest();
    void PrintClientsAndAccounts() const;

    void Deposit(int accountNumber, double amount);
    void Withdraw(int accountNumber, double amount);
};

#endif // BANK_H
