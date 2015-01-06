#include "bank.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

#include "account.h"

Bank::Bank(const char *data_file)
{
    this->data_file = data_file;
    std::ifstream infile(data_file, std::ios::in);
    if(infile) {
        // If a data file exists, start with reading next_account_number.
        // This is always found on the first line of a datafile and is used when creating new accounts.
        infile >> Account::next_account_number;
        Account acc;
        while(infile >> acc) {
            // Read an account. If it is active, allocate memory for it and add the pointer to
            // both of the data structures.
            if(acc.is_active()) {
                Account* acc_ptr = new Account(acc.get_number(), acc.is_active(), acc.get_type(), acc.get_owner(), acc.get_balance());
                accounts_by_number.insert(std::pair<int, Account*>(acc.get_number(), acc_ptr));
                accounts_by_owner.insert(std::pair<std::string, Account*>(acc.get_owner(), acc_ptr));
            }
        }
        infile.close();
    } else {
        // If no data file is found, assume that we are starting fresh. In this case next_account_number
        // is set to 1000000 (which is "the first" account number), and save it to the first line of a new file.
        Account::next_account_number = 1000000;
        std::ofstream outfile(data_file, std::ios::out);
        if(outfile) {
            outfile << Account::next_account_number << std::endl;
            outfile.close();
        }
    }
}

Bank::~Bank()
{
    // Frees the dynamically allocated memory.
    for(std::map<int, Account*>::iterator it = accounts_by_number.begin(); it != accounts_by_number.end(); ++it) {
        delete it->second;
    }
}

int Bank::openAccount(account_t type, std::string owner)
{
    // Allocate memory for a new account, and add its pointer to both data structures.
    // Write the new account to file.
    Account* account = new Account(type, owner);
    accounts_by_number.insert(std::pair<int, Account*>(account->get_number(), account));
    accounts_by_owner.insert(std::pair<std::string, Account*>(account->get_owner(), account));
    storeAccount(account);
    return account->get_number();
}

bool Bank::closeAccount(int account)
{
    Account* acc = findAccountByNumber(account);
    if(acc == NULL) return false;
    accounts_by_number.erase(account);
    // Since a person can have multiple accounts we have to:
    // 1) get the owner ID from the account
    // 2) get all accounts for that owner ID
    // 3) iterate over all of the found accounts
    //    a) when the account is found, remove that account from the data structure and exit loop
    // When the account is removed from both data structures, it is simply a matter of setting the
    // account as inactive and storing that change.
    std::string owner = acc->get_owner();
    std::pair<std::multimap<std::string, Account*>::iterator, std::multimap<std::string, Account*>::iterator> ret;
    ret = accounts_by_owner.equal_range(owner);
    for(std::multimap<std::string, Account*>::iterator it = ret.first; it != ret.second; ++it) {
        if(it->second->get_number() == account) {
            accounts_by_owner.erase(it);
            break;
        }
    }
    acc->set_active(false);
    storeAccount(acc);
    return true;
}

std::vector<Account*> Bank::getAllAccounts()
{
    std::vector<Account*> output;
    for(auto m : accounts_by_number) {
        output.push_back(m.second);
    }
    return output;
}

Account* Bank::findAccountByNumber(int account)
{
    std::map<int, Account*>::iterator it = accounts_by_number.find(account);
    return it != accounts_by_number.end() ? it->second : NULL;
}

std::vector<Account*> Bank::findAccountsByOwner(std::string owner)
{
    // Create a vector of all accounts for the specified owner
    std::pair<std::multimap<std::string, Account*>::iterator, std::multimap<std::string, Account*>::iterator> ret;
    ret = accounts_by_owner.equal_range(owner);
    std::vector<Account*> output;
    for(std::multimap<std::string, Account*>::iterator it = ret.first; it != ret.second; ++it)
        output.push_back(it->second);
    return output;
}

void Bank::storeAccount(Account* account)
{
    std::string temp_file = std::string(data_file) + "~";
    std::ifstream if1(data_file, std::ios::in);
    std::ofstream of1(temp_file, std::ios::out);

    if1.ignore(20, '\n'); // Skip first line
    of1 << Account::next_account_number << std::endl;

    // Write contents of data file to temporary file.
    // If the account to be stored is encountered, it is updated.
    Account temp_account;
    bool found = false;
    while(if1 >> temp_account) {
        if(temp_account.get_number() == account->get_number()) {
            found = true;
            of1 << *account;
        }
        else of1 << temp_account;
    }
    // The account was not found, append it to the end.
    if(!found) of1 << *account;
    if1.close();
    of1.close();

    // Write the temporary file back to the original file.
    std::ifstream if2(temp_file, std::ios::in);
    std::ofstream of2(data_file, std::ios::out);
    of2 << if2.rdbuf();
    if2.close();
    of2.close();
    std::remove(temp_file.c_str());
}

bool Bank::deposit(int account, double amount)
{
    Account* acc = findAccountByNumber(account);
    if(acc == NULL) return false;
    else if(!acc->deposit(amount)) return false;
    else {
        storeAccount(acc);
        return true;
    }
}

bool Bank::withdraw(int account, double amount)
{
    Account* acc = findAccountByNumber(account);
    if(acc == NULL) return false;
    else if(!acc->withdraw(amount)) return false;
    else {
        storeAccount(acc);
        return true;
    }
}

bool Bank::modifyAccountType(int account, account_t type)
{
    Account* acc = findAccountByNumber(account);
    if(acc == NULL) return false;
    else {
        acc->set_type(type);
        storeAccount(acc);
        return true;
    }
}

bool Bank::modifyAccountOwner(int account, std::string owner)
{
    Account* acc = findAccountByNumber(account);
    if(acc == NULL) return false;
    else {
        acc->set_owner(owner);
        storeAccount(acc);
        return true;
    }
}
