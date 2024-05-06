#include "bank.h"
#include <iostream>

using namespace std;

Bank::Bank(int c, int a) : clientsCount(0), accountsCount(0), maxClients(c), maxAccounts(a) {
    clients = new Client * [maxClients];
    accounts = new Account * [maxAccounts];
}

Bank::~Bank() {
    for (int i = 0; i < clientsCount; ++i)
        delete clients[i];
    delete[] clients;

    for (int i = 0; i < accountsCount; ++i)
        delete accounts[i];
    delete[] accounts;
}

Client* Bank::GetClient(int c) const {
    for (int i = 0; i < clientsCount; ++i) {
        if (clients[i]->GetCode() == c)
            return clients[i];
    }
    return nullptr;
}

Account* Bank::GetAccount(int n) const {
    for (int i = 0; i < accountsCount; ++i) {
        if (accounts[i]->GetNumber() == n)
            return accounts[i];
    }
    return nullptr;
}

Client* Bank::CreateClient(int c, string n) {
    if (clientsCount < maxClients) {
        clients[clientsCount] = new Client(c, n);
        return clients[clientsCount++];
    }
    return nullptr;
}

Account* Bank::CreateAccount(int n, Client* c) {
    if (accountsCount < maxAccounts) {
        accounts[accountsCount] = new Account(n, c);
        return accounts[accountsCount++];
    }
    return nullptr;
}

Account* Bank::CreateAccount(int n, Client* c, double ir) {
    if (accountsCount < maxAccounts) {
        accounts[accountsCount] = new Account(n, c, ir);
        return accounts[accountsCount++];
    }
    return nullptr;
}

PartnerAccount* Bank::CreateAccount(int n, Client* c, Client* p, double ir) {
    if (accountsCount < maxAccounts) {
        accounts[accountsCount] = new PartnerAccount(n, c, p, ir);
        return static_cast<PartnerAccount*>(accounts[accountsCount++]);
    }
    return nullptr;
}

void Bank::AddInterest() {
    for (int i = 0; i < accountsCount; ++i) {
        double ir = accounts[i]->GetInterestRate();
        if (ir > 0)
            accounts[i]->AddInterest();
    }
}

void Bank::PrintClientsAndAccounts() const {
    cout << "List of clients and their accounts:" << endl;
    for (int i = 0; i < clientsCount; ++i) {
        Client* client = clients[i];
        cout << "Client: " << client->GetName() << endl;
        cout << "Accounts:" << endl;
        for (int j = 0; j < accountsCount; ++j) {
            Account* account = accounts[j];
            if (account->GetOwner() == client) {
                cout << "   Account number: " << account->GetNumber() << ", Balance: " << account->GetBalance() << endl;
            }
        }
        cout << endl;
    }
}

void Bank::Deposit(int accountNumber, double amount) {
    Account* account = GetAccount(accountNumber);

    if (account) {
        account->Deposit(amount);
        cout << "vklad vporiadku. Novy zostatok:" << account->GetBalance() << endl;
    }
   
}

void Bank::Withdraw(int accountNumber, double amount) {
    Account* account = GetAccount(accountNumber);

    if (account) {
        if (account->Withdraw(amount)) {
            cout << "vyber vporiadku. Novy zostatok:" << account->GetBalance() << endl;
        }
        else {
            cout << "Chyba nedostatok na ucte." << endl;
        }
    }
   
}
