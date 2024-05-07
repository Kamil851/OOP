#include "account.h"

Account::Account(int n, Client* o) : number(n), owner(o), balance(0), interestRate(0) {}

Account::Account(int n, Client* o, double ir) : number(n), owner(o), balance(0), interestRate(ir) {}

int Account::GetNumber() {
    return number;
}

double Account::GetBalance() {
    return balance;
}

double Account::GetInterestRate() {
    return interestRate;
}

Client* Account::GetOwner() {
    return owner;
}

bool Account::CanWithdraw(double a) {
    return (balance >= a);
}

void Account::Deposit(double a) {
    balance += a;
}

bool Account::Withdraw(double a) {
    bool success = false;
    if (CanWithdraw(a)) {
        balance -= a;
        success = true;
    }
    return success;
}

void Account::AddInterest() {
    balance += balance * interestRate;
}
