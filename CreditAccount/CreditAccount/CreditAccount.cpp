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
    // Vytvo�en� klienta
    Client client("John Doe", "123 Main Street");

    // Vytvo�en� b�n�ho ��tu
    Account account(123456, &client, 0.02);

    // Vytvo�en� kreditn�ho ��tu
    CreditAccount creditAccount(654321, &client, 0.03, 500);

    // V�pis informac� o klientovi
    std::cout << "Client Name: " << client.GetName() << std::endl;
    std::cout << "Client Address: " << client.GetAddress() << std::endl;

    // V�pis informac� o b�n�m ��tu
    std::cout << "Account Number: " << account.GetNumber() << std::endl;
    std::cout << "Account Balance: " << account.GetBalance() << std::endl;
    std::cout << "Account Interest Rate: " << account.GetInterestRate() << std::endl;

    // V�pis informac� o kreditn�m ��tu
    std::cout << "Credit Account Number: " << creditAccount.GetNumber() << std::endl;
    std::cout << "Credit Account Balance: " << creditAccount.GetBalance() << std::endl;
    std::cout << "Credit Account Interest Rate: " << creditAccount.GetInterestRate() << std::endl;

    // P�id�n� pen�z na b�n� ��et a v�pis nov�ho z�statku
    account.Deposit(1000);
    std::cout << "New Account Balance after Deposit: " << account.GetBalance() << std::endl;

    // P�id�n� pen�z na kreditn� ��et a v�pis nov�ho z�statku
    creditAccount.Deposit(500);
    std::cout << "New Credit Account Balance after Deposit: " << creditAccount.GetBalance() << std::endl;

    // V�b�r pen�z z b�n�ho ��tu a v�pis nov�ho z�statku
    account.Withdraw(200);
    std::cout << "New Account Balance after Withdrawal: " << account.GetBalance() << std::endl;

    // V�b�r pen�z z kreditn�ho ��tu a v�pis nov�ho z�statku
    creditAccount.Withdraw(300);
    std::cout << "New Credit Account Balance after Withdrawal: " << creditAccount.GetBalance() << std::endl;

    return 0;
}
