#include "Account.h"

AbstractAccount::AbstractAccount() {
    std::cout << "AbstractAccount constructor" << std::endl;
}

AbstractAccount::~AbstractAccount() {
    std::cout << "AbstractAccount destructor" << std::endl;
}

Client::Client(int id, const std::string& name) : id(id), name(name) {}

Client::~Client() {
    std::cout << "Client destructor" << std::endl;
}

Account::Account(int n, Client* o) : number(n), balance(0), interestRate(0), owner(o) {}

Account::Account(int n, Client* o, double ir) : number(n), balance(0), interestRate(ir), owner(o) {}

Account::~Account() {
    std::cout << "Account destructor" << std::endl;
}

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
    if (CanWithdraw(a)) {
        balance -= a;
        return true;
    }
    return false;
}

void Account::AddInterest() {
    balance += balance * (interestRate / 100.0);
}
