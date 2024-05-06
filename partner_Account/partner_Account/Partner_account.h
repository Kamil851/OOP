#pragma once
#ifndef PARTNER_ACCOUNT_H
#define PARTNER_ACCOUNT_H

#include "account.h"

class PartnerAccount : public Account {
private:
    Client* partner;

public:
    PartnerAccount(int n, Client* o, Client* p);
    PartnerAccount(int n, Client* o, Client* p, double ir);

    Client* GetPartner() const;
};

#endif // PARTNER_ACCOUNT_H
