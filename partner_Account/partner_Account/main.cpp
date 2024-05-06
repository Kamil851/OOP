#include "bank.h"
#include <iostream>

using namespace std;

int main() {
    Account* a;
    PartnerAccount* pa;

    Bank* b = new Bank(100, 1000);
    Client* o = b->CreateClient(0, "Jozef");
    Client* p = b->CreateClient(1, "Mrkvicka");
    a = b->CreateAccount(0, o);
    pa = b->CreateAccount(1, o, p, 0.02);

    cout << "Owner of Account a: " << a->GetOwner()->GetName() << endl;
    cout << "Partner of Account pa: " << static_cast<PartnerAccount*>(pa)->GetPartner()->GetName() << endl;

    
    delete b;

    return 0;
}
