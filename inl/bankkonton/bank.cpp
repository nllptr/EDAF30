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
            accounts.push_back(acc);
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
    accounts.push_back(account);
    storeAccount(account);
    return account.get_number();
}

const std::vector<Account> Bank::getAccounts() {
    return accounts;
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
