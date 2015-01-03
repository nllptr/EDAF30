#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

#include "bank.h"
#include "account.h"

using namespace std;

// This bank uses seven digit account numbers.
int Account::next_account_number;

char *data_file = (char *)"datafile";
Bank *bank;

string getCommand(string prompt);
void openAccount();
void showInfo(vector<Account*> accounts);
void showInfoByOwner();
void showInfoByNumber(int account);
void showHelp();
int selectAccount();
void deposit(int account);
void withdraw(int account);

int main()
{
    bank = new Bank(data_file);

    cout << "================" << endl;
    cout << " Superbank v0.1" << endl;
    cout << "================" << endl << endl;
    cout << "Type ? for help." << endl << endl;

    while(true) {
        string command = getCommand("Superbank");

        if(command == "Q") break;
        else if(command == "?") showHelp();
        else if(command == "LA") showInfo(bank->getAllAccounts());
        else if(command == "LO") showInfoByOwner();
        else if(command == "O") openAccount();
        else if(command == "S") {
            int account = selectAccount();
            while(account > 0) {
                command = getCommand("Superbank>" + to_string(account));
                if(command == "Q") break;
                else if(command == "?") showHelp();
                else if(command == "I") showInfoByNumber(account);
                else if(command == "D") deposit(account);
                else if(command == "W") withdraw(account);
            }
        } else cout << "Unrecognized command. Try again." << endl;
    }

    cout << "Bye!" << endl;
    delete bank;
    return 0;
}

string getCommand(string prompt)
{
    cout << prompt << "> ";
    string command;
    cin >> command;
    for(auto &c : command) c = toupper(c); // Convert command to upper case. Makes checking checking easier.
    return command;
}

void openAccount()
{
    cout << "What kind of account (1: Checking, 2: Savings)? ";
    int type;
    while(!(cin >> type)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, try again: ";
    }
    while(type < 1 || type > COUNT) {
        cout << "Invalid account type. Try again." << endl;
        return openAccount();
    }
    cout << "Enter ID of the account owner: ";
    string owner_id;
    cin >> owner_id;
    cout << "Created account: " << bank->openAccount(static_cast<account_t>(--type), owner_id) << endl;
}

void showInfo(vector<Account*> accounts)
{
    if(accounts.size() > 0) {
        for(Account* a : accounts) {
            cout << endl;
            a->print_info();
        }
    } else {
        cout << endl << "No accounts found matching the criteria." << endl;
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

void showInfoByNumber(int account)
{
    cout << endl;
    bank->findAccountByNumber(account)->print_info();
    cout << endl;
}

int selectAccount()
{
    cout << "Enter account number: ";
    int account;
    while(!(cin >> account)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "HINT: Account numbers are seven digit integers." << endl;
        return selectAccount();
    }
    Account* acc = bank->findAccountByNumber(account);
    if(acc == NULL) {
        cout << "Account does not exist." << endl;
        return -1;
    }
    else return account;
}

void showHelp()
{
    cout << endl << "la\tList all accounts" << endl;
    cout << "lo\tList all accounts belonging to specific owner" << endl;
    cout << "s\tSelect account" << endl;
    cout << "\tOnce an account is selected you can issue the following commands:" << endl << endl;
    cout << "\ti\tShow account information" << endl;
    cout << "\td\tDeposit" << endl;
    cout << "\tw\tWithdraw" << endl;
    cout << "\tm\tModify account" << endl;
    cout << "\tc\tClose account" << endl << endl;
    cout << "o\tOpen account" << endl;
    cout << "q\tQuit program/exit the currently selected account" << endl;
    cout << "?\tShow help" << endl << endl;
}

void deposit(int account)
{
    cout << "Enter amount: ";
    double amount;
    while(!(cin >> amount)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "HINT: Use decimal point (.) as decimal separator." << endl;
        return deposit(account);
    }
    if(!bank->deposit(account, amount)) cout << "Deposit unsuccessful." << endl;
}

void withdraw(int account)
{
    cout << "Enter amount: ";
    double amount;
    while(!(cin >> amount)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "HINT: Use decimal point (.) as decimal separator." << endl;
        return withdraw(account);
    }
    if(!bank->withdraw(account, amount)) cout << "Withdrawal unsuccessful." << endl;
}
