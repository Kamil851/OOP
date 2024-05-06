#include "account.h"

int Account::objectsCount = 0;

int Account::GetObjectsCount() {
    return objectsCount;
}

Account::Account(int n, Client* o) : number(n), owner(o), balance(0), interestRate(0) {
    objectsCount++;
}

Account::Account(int n, Client* o, double ir) : number(n), owner(o), balance(0), interestRate(ir) {
    objectsCount++;
}

Account::~Account() {
    objectsCount--;
}

int Account::GetNumber() const {
    return number;
}

double Account::GetBalance() const {
    return balance;
}

double Account::GetInterestRate() const {
    return interestRate;
}

Client* Account::GetOwner() const {
    return owner;
}

bool Account::CanWithdraw(double a) const {
    return balance >= a;
}

void Account::Deposit(double a) {
    balance += a;
}

bool Account::Withdraw(double a) {
    if (CanWithdraw(a)) {
        balance -= a;
        return true;
    }
    return false;
}

void Account::AddInterest() {
    balance += balance * interestRate;
}
