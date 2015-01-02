#ifndef BANK_H
#define BANK_H

#include "account.h"

#include <vector>
#include <map>

class SortByAccountNumber
{
public:
    bool operator() (const Account& lhs, const Account& rhs)
    {
        return lhs.get_number() < rhs.get_number();
    }
};

class SortByAccountOwner
{
public:
    bool operator() (const Account& lhs, const Account& rhs)
    {
        if(lhs.get_owner() == rhs.get_owner()) return lhs.get_number() < rhs.get_number();
        else return lhs.get_owner() < rhs.get_owner();
    }
};

class Bank
{
public:
    Bank(char *data_file);
    //~Bank();
    int openAccount(account_t type, std::string owner);
    const std::vector<Account> getAllAccounts() const;
    void storeAccount(Account &account);
    Account findAccountByNumber(int account);
    std::vector<Account> findAccountsByOwner(std::string owner);
private:
    //std::vector<Account> accounts;
    std::map<int, Account> accounts_by_number;
    std::multimap<std::string, Account> accounts_by_owner;
    char *data_file;
};

#endif // BANK_H
