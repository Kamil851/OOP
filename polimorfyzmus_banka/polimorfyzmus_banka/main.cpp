
#include <iostream>
#include "Client.h"
#include "Account.h"

using namespace std;

class CreditAccount : public Account {
private:
    double credit;

public:
    CreditAccount(int n, Client* o, double c);
    CreditAccount(int n, Client o, double ir, double c);
    bool CanWithdraw(double a) override; 
};


Account::Account(int n, Client* o) : number(n), owner(*o), balance(0), interestRate(0) {}

Account::Account(int n, Client* o, double ir) : number(n), owner(*o), balance(0), interestRate(ir) {}

bool Account::CanWithdraw(double a) {
    return (balance >= a);
}


CreditAccount::CreditAccount(int n, Client* o, double c) : Account(n, o), credit(c) {}

CreditAccount::CreditAccount(int n, Client o, double ir, double c) : Account(n, &o, ir), credit(c) {}

bool CreditAccount::CanWithdraw(double a) {
    return (GetBalance() + credit >= a);
}

int main() {
    Client client("John Doe", "123 Main Street");
    Account* acc = new CreditAccount(123, &client, 1000.0);

    if (acc->CanWithdraw(500.0)) {
        cout << "Vyber presiel\n";
    }
    else {
        cout << "Nedostatok prostriedkov na ucte\n";
    }

    delete acc;
    return 0;
}
