#include "credit_account.h"

CreditAccount::CreditAccount(int n, Client* o, double c) : Account(n, o), credit(c) {}

CreditAccount::CreditAccount(int n, Client* o, double ir, double c) : Account(n, o, ir), credit(c) {}

bool CreditAccount::CanWithdraw(double a) {
    return (balance + credit >= a);
}

bool CreditAccount::Withdraw(double a) {
    bool success = false;
    if (CanWithdraw(a)) {
        balance -= a;
        success = true;
    }
    return success;
}
