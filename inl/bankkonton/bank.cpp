#include "bank.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "account.h"

Bank::Bank(char *data_file)
{
    this->data_file = data_file;
    std::ifstream infile(data_file, std::ios::in);
    if(infile) {
        // File exists
        infile >> Account::next_account_number;
        Account acc;
        while(infile >> acc) {
            //accounts.push_back(acc);
            accounts_by_number.insert(std::pair<int, Account>(acc.get_number(), acc));
            accounts_by_owner.insert(std::pair<std::string, Account>(acc.get_owner(), acc));
        }
        infile.close();
    } else {
        // This is the default starting account number.
        Account::next_account_number = 1000000;
        std::ofstream outfile(data_file, std::ios::out);
        if(outfile) {
            outfile << Account::next_account_number << std::endl;
            outfile.close();
        }
    }
}

int Bank::openAccount(account_t type, std::string owner)
{
    Account account(type, owner);
    //accounts.push_back(account);
    accounts_by_number.insert(std::pair<int, Account>(account.get_number(), account));
    accounts_by_owner.insert(std::pair<std::string, Account>(account.get_owner(), account));
    storeAccount(account);
    return account.get_number();
}

const std::vector<Account> Bank::getAllAccounts() const
{
    std::vector<Account> output;
    for(auto m : accounts_by_number) {
        output.push_back(m.second);
    }
    return output;
}

Account Bank::findAccountByNumber(int account)
{
    std::map<int, Account>::iterator it = accounts_by_number.find(account);
    return it != accounts_by_number.end() ? it->second : Account();
}

std::vector<Account> Bank::findAccountsByOwner(std::string owner)
{
    std::pair<std::multimap<std::string, Account>::iterator, std::multimap<std::string, Account>::iterator> ret;
    ret = accounts_by_owner.equal_range(owner);
    std::vector<Account> output;
    for(std::multimap<std::string, Account>::iterator it = ret.first; it != ret.second; ++it)
        output.push_back(it->second);
    return output;
}

void Bank::storeAccount(Account &account)
{
    char *temp_file = std::tmpnam(NULL);
    std::ifstream if1(data_file, std::ios::in);
    std::ofstream of1(temp_file, std::ios::out);

    if1.ignore(20, '\n'); // Skip first line
    of1 << Account::next_account_number << std::endl;

    // Write contents of data file to temporary file.
    // If the account to be stored is encountered, it is updated.
    Account temp_account;
    bool found = false;
    while(if1 >> temp_account) {
        if(temp_account.get_number() == account.get_number()) {
            found = true;
            of1 << account;
        }
        else of1 << temp_account;
    }
    // The account was not found, append it to the end.
    if(!found) of1 << account;
    if1.close();
    of1.close();

    // Write the temporary file back to the original file.
    std::ifstream if2(temp_file, std::ios::in);
    std::ofstream of2(data_file, std::ios::out);
    of2 << if2.rdbuf();
}
