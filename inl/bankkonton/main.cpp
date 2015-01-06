#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype>

#include "bank.h"
#include "account.h"

using namespace std;

// To access the static variable in Account, it has to be declared here.
int Account::next_account_number;

string data_file = "datafile";
Bank *bank;
int selected_account;

// Function prototypes
string getCommand(string prompt);
void openAccount();
void closeAccount(int account);
void showInfo(vector<Account*> accounts);
void showInfoByOwner();
void showInfoByNumber(int account);
void showHelp();
int selectAccount();
void deposit(int account);
void withdraw(int account);
void modifyType(int account);
void modifyOwner(int account);

int main()
{
    bank = new Bank(data_file.c_str());
    selected_account = -1;

    cout << "================" << endl;
    cout << " Superbank v0.1" << endl;
    cout << "================" << endl << endl;
    cout << "Type ? for help." << endl << endl;

    while(true) {
        string command = getCommand("[Selected account: " + (selected_account < 0 ? "NONE" : to_string(selected_account)) + "]");

        if(command == "Q") break;
        else if(command == "?") showHelp();
        else if(command == "LA") showInfo(bank->getAllAccounts());
        else if(command == "LO") showInfoByOwner();
        else if(command == "O") openAccount();
        else if(command == "I" || command == "D" || command == "W" || command == "MT" || command == "MO" || command == "C") {
            if(selected_account < 0) cout << "You need to select an account before issuing this command." << endl;
            else if(command == "I") showInfoByNumber(selected_account);
            else if(command == "D") deposit(selected_account);
            else if(command == "W") withdraw(selected_account);
            else if(command == "MT") modifyType(selected_account);
            else if(command == "MO") modifyOwner(selected_account);
            else if(command == "C") closeAccount(selected_account);
        } else if(command == "S") selected_account = selectAccount();
        else cout << "Unrecognized command. Try again." << endl;
    }

    cout << "Bye!" << endl;
    delete bank;
    return 0;
}

string getCommand(string prompt)
{
    cout << prompt << "$ ";
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

void closeAccount(int account)
{
    cout << "Are you sure you want to close account " << account << " (yes/no)? ";
    string input;
    cin >> input;
    if(input == "yes") {
        bank->closeAccount(account);
        selected_account = -1;
        cout << "Account closed." << endl;
    } else {
        cout << "Account not closed." << endl;
    }
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
    cout << "\tmt\tModify account type" << endl;
    cout << "\tmo\tModify account owner" << endl;
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

void modifyType(int account)
{
    cout << "Enter new account type (1: Checking, 2: Savings): ";
    int type;
    while(!(cin >> type)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, try again: ";
    }
    while(type < 1 || type > COUNT) {
        cout << "Invalid account type. Try again." << endl;
        return modifyType(account);
    }
    if(!bank->modifyAccountType(account, static_cast<account_t>(--type))) cout << "Account type change uncuccessful." << endl;

}

void modifyOwner(int account)
{
    cout << "Enter new account owner ID: ";
    string owner;
    cin >> owner;
    if(!bank->modifyAccountOwner(account, owner)) cout << "Account owner change unsuccessful." << endl;
}
