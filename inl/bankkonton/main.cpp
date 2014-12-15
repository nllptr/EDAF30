#include <iostream>
#include <fstream>

#include "bank.h"
#include "account.h"

using namespace std;

// This bank uses seven digit acount numbers.
int Account::next_account_number;

char *data_file = (char *)"datafile";

void openAccount(Bank &bank);
void showHelp();

int main()
{
    Bank bank(data_file);
    cout << Account::next_account_number << endl;

    cout << "================" << endl;
    cout << " Superbank v0.1" << endl;
    cout << "================" << endl << endl;
    cout << "Type ? for help." << endl << endl;

    while(true) {
        cout << "Enter command: ";
        string command;
        cin >> command;

        if(command == "Q" || command == "q") break;
        else if(command == "O" || command == "o") openAccount(bank);
        else if(command == "?") showHelp();
        else cout << "Unrecognized command. Try again." << endl;
    }

    cout << "Bye!" << endl;
    return 0;
}

void openAccount(Bank &bank)
{
    cout << "What kind of account (1. Checking, 2. Savings)? ";
    int type;
    cin >> type;
    if(type < 0 || type > COUNT) {
        cout << "Invalid account type. Aborting." << endl;
        return;
    }
    //char name_char[80];
    cout << "Enter ID of the account owner: ";
    string name;
    cin >> ws;
    getline(cin, name);
    //cin.getline(name_char, 80);
    //string name_string(name_char);
    cout << "Created account: " << bank.openAccount(static_cast<account_t>(type), name) << endl;
}

void showHelp()
{
    cout << "(O)pen account" << endl;
    cout << "(C)lose account" << endl;
    cout << "Show info for (a)ll accounts" << endl;
    cout << "Show info for (s)pecific account" << endl;
}
