#include <iostream>
#include <string>

class Client {
private:
    std::string name;
    std::string address;

public:
    Client(const std::string& n, const std::string& addr);
    std::string GetName() const;
    std::string GetAddress() const;
};

Client::Client(const std::string& n, const std::string& addr) : name(n), address(addr) {}

std::string Client::GetName() const {
    return name;
}

std::string Client::GetAddress() const {
    return address;
}

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

class CreditAccount : public Account {
private:
    double credit;

public:
    CreditAccount(int n, Client* o, double c);
    CreditAccount(int n, Client* o, double ir, double c);

    bool CanWithdraw(double a);
    bool Withdraw(double a);
};

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

int main() {
    // Vytvoøení klienta
    Client client("John Doe", "123 Main Street");

    // Vytvoøení bìžného úètu
    Account account(123456, &client, 0.02);

    // Vytvoøení kreditního úètu
    CreditAccount creditAccount(654321, &client, 0.03, 500);

    // Výpis informací o klientovi
    std::cout << "Client Name: " << client.GetName() << std::endl;
    std::cout << "Client Address: " << client.GetAddress() << std::endl;

    // Výpis informací o bìžném úètu
    std::cout << "Account Number: " << account.GetNumber() << std::endl;
    std::cout << "Account Balance: " << account.GetBalance() << std::endl;
    std::cout << "Account Interest Rate: " << account.GetInterestRate() << std::endl;

    // Výpis informací o kreditním úètu
    std::cout << "Credit Account Number: " << creditAccount.GetNumber() << std::endl;
    std::cout << "Credit Account Balance: " << creditAccount.GetBalance() << std::endl;
    std::cout << "Credit Account Interest Rate: " << creditAccount.GetInterestRate() << std::endl;

    // Pøidání penìz na bìžný úèet a výpis nového zùstatku
    account.Deposit(1000);
    std::cout << "New Account Balance after Deposit: " << account.GetBalance() << std::endl;

    // Pøidání penìz na kreditní úèet a výpis nového zùstatku
    creditAccount.Deposit(500);
    std::cout << "New Credit Account Balance after Deposit: " << creditAccount.GetBalance() << std::endl;

    // Výbìr penìz z bìžného úètu a výpis nového zùstatku
    account.Withdraw(200);
    std::cout << "New Account Balance after Withdrawal: " << account.GetBalance() << std::endl;

    // Výbìr penìz z kreditního úètu a výpis nového zùstatku
    creditAccount.Withdraw(300);
    std::cout << "New Credit Account Balance after Withdrawal: " << creditAccount.GetBalance() << std::endl;

    return 0;
}
