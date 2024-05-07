#include <iostream>
#include "client.h"
#include "account.h"
#include "credit_account.h"

using namespace std;

int main() {
    Client client("John Doe", "123 Main Street");

    Account account(123456, &client, 0.02);

    CreditAccount creditAccount(654321, &client, 0.03, 500);

    cout << "Client Name: " << client.GetName() << endl;
    cout << "Client Address: " << client.GetAddress() << endl;

    cout << "Account Number: " << account.GetNumber() << endl;
    cout << "Account Balance: " << account.GetBalance() << endl;
    cout << "Account Interest Rate: " << account.GetInterestRate() << endl;

    cout << "Credit Account Number: " << creditAccount.GetNumber() << endl;
    cout << "Credit Account Balance: " << creditAccount.GetBalance() << endl;
    cout << "Credit Account Interest Rate: " << creditAccount.GetInterestRate() << endl;

    account.Deposit(1000);
    cout << "New Account Balance after Deposit: " << account.GetBalance() << endl;

    creditAccount.Deposit(500);
    cout << "New Credit Account Balance after Deposit: " << creditAccount.GetBalance() << endl;

    account.Withdraw(200);
    cout << "New Account Balance after Withdrawal: " << account.GetBalance() << endl;

    
    creditAccount.Withdraw(300);
    cout << "New Credit Account Balance after Withdrawal: " << creditAccount.GetBalance() << endl;

    return 0;
}
