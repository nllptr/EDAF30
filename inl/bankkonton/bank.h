#ifndef BANK_H
#define BANK_H

#include "account.h"

#include <vector>
#include <map>

class Bank
{
public:
    Bank(const char *data_file);
    ~Bank();
    int openAccount(account_t type, std::string owner);
    bool closeAccount(int account);
    std::vector<Account*> getAllAccounts();
    void storeAccount(Account* account);
    Account* findAccountByNumber(int account);
    std::vector<Account*> findAccountsByOwner(std::string owner);
    bool deposit(int account, double amount);
    bool withdraw(int account, double amount);
    bool modifyAccountType(int account, account_t type);
    bool modifyAccountOwner(int account, std::string owner);
private:
    std::map<int, Account*> accounts_by_number;
    // accounts_by_owner needs to be a multimap, since a person can have multiple accounts
    std::multimap<std::string, Account*> accounts_by_owner;
    const char *data_file;
};

#endif // BANK_H
