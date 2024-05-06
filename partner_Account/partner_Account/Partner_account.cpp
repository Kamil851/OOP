#include "partner_account.h"

PartnerAccount::PartnerAccount(int n, Client* o, Client* p) : Account(n, o) {
    partner = p;
}

PartnerAccount::PartnerAccount(int n, Client* o, Client* p, double ir) : Account(n, o, ir) {
    partner = p;
}

Client* PartnerAccount::GetPartner() const {
    return partner;
}
