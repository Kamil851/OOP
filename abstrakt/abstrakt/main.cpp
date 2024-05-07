#include "Account.h"

using namespace std;

int main() {
    Client* o = new Client(0, "Smith");
    Account* ca = new Account(1, o, 1.5);

    cout << "Initial Balance: " << ca->GetBalance() << endl;
    ca->Deposit(1000);
    cout << "Balance after deposit: " << ca->GetBalance() << endl;

    if (ca->Withdraw(500))
        cout << "Withdrawal successful" << endl;
    else
        cout << "Insufficient funds" << endl;

    ca->AddInterest();
    cout << "Balance after interest: " << ca->GetBalance() << endl;

    delete ca;
    delete o;

    getchar();
    return 0;
}
