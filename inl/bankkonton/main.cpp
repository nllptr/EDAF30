#include <iostream>
#include <fstream>

#include "bank.h"
#include "account.h"

using namespace std;

// This bank uses seven digit account numbers.
int Account::next_account_number;

char *data_file = (char *)"datafile";
Bank *bank;

void openAccount();
void showInfo(vector<Account> accounts);
void showInfoByOwner();
void showInfoByNumber();
void showHelp();

int main()
{
    bank = new Bank(data_file);
    cout << Account::next_account_number << endl;
    //int selected_account = 0;

    cout << "================" << endl;
    cout << " Superbank v0.1" << endl;
    cout << "================" << endl << endl;
    cout << "Type ? for help." << endl << endl;

    while(true) {
        //cout << "Selected account: " << (selected_account == 0 ? "NONE" : to_string(selected_account)) << endl;
        cout << "Enter command: ";
        string command;
        cin >> command;

        if(command == "Q" || command == "q") break;
        else if(command == "O" || command == "o") openAccount();
        else if(command == "A" || command == "a") showInfo(bank->getAllAccounts());
        else if(command == "W" || command == "w") showInfoByOwner();
        else if(command == "S" || command == "s") showInfoByNumber();
        else if(command == "?") showHelp();
        else cout << "Unrecognized command. Try again." << endl;
    }

    cout << "Bye!" << endl;
    delete bank;
    return 0;
}

void openAccount()
{
    cout << "What kind of account (1. Checking, 2. Savings)? ";
    int type;
    cin >> type;
    if(type < 1 || type > COUNT) {
        cout << "Invalid account type. Aborting." << endl;
        return;
    }
    cout << "Enter ID of the account owner: ";
    string owner_id;
    cin >> ws;
    getline(cin, owner_id);
    cout << "Created account: " << bank->openAccount(static_cast<account_t>(--type), owner_id) << endl;
}

void showInfo(vector<Account> accounts)
{
    if(accounts.size() > 0) {
        for(Account a : accounts) {
            cout << endl;
            a.print_info();
        }
    } else {
        cout << endl << "No accounts found matching the criteria" << endl;
    }
    cout << endl;
}

void showInfoByOwner()
{
    string owner;
    cout << "Enter account owner: ";
    cin >> owner;
    showInfo(bank->findAccountsByOwner(owner));
}

void showInfoByNumber()
{
    int account;
    cout << "Enter account number: ";
    cin >> account;
    cout << endl;
    Account found = bank->findAccountByNumber(account);
    if(found.get_number() != 0) found.print_info();
    else cout << "No account found matching the criteria" << endl;
    cout << endl;
}

void showHelp()
{
    cout << endl << "O: Open account" << endl;
    cout << "C: Close account" << endl;
    cout << "A: Show info for all accounts" << endl;
    cout << "W: Show accounts for specific owner" << endl;
    cout << "S: Show info for specific account" << endl;
    cout << "Q: Quit" << endl;
    cout << "?: Show help" << endl << endl;
}
