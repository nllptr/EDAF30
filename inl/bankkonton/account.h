#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
//#include <iostream>

// Count is used to find how many elements there are in the enum.
enum account_t { CHECKING, SAVINGS, COUNT };

class Account
{
public:
    static int next_account_number;
    Account() : account_number(0), account_type(COUNT), account_owner("undefined"), account_balance(0) {}
    Account(account_t type, std::string owner, double balance = 0)
        : account_number(next_account_number), account_type(type), account_owner(owner), account_balance(balance)
        { next_account_number++; }

    // Getters and setters.
    int get_number() { return account_number; }
    //void set_number(int number) { account_number = number; } // For safety, it should not be possible to change account number.
    account_t get_type() { return account_type; }
    void set_type(account_t type) { account_type = type; }
    std::string get_owner() { return account_owner; }
    void set_owner(std::string owner) { account_owner = owner; }
    double get_balance() { return account_balance; }
    void set_balance(double balance) { account_balance = balance; }
    void print_info();

    // Operator overloading for convenience
    friend std::ostream& operator<<(std::ostream& o, Account& a);
    friend std::istream& operator>>(std::istream& i, Account& a);
private:
    int account_number;
    account_t account_type;
    std::string account_owner;
    double account_balance;
};

#endif // ACCOUNT_H
