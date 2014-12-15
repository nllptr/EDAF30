#ifndef BANK_H
#define BANK_H

#include "account.h"

#include <vector>

class Bank
{
public:
    Bank(char *data_file);
    //~Bank();
    int openAccount(account_t type, std::string owner);
    const std::vector<Account> getAccounts();
    void storeAccount(Account &account);
private:
    std::vector<Account> accounts;
    char *data_file;
};

#endif // BANK_H
