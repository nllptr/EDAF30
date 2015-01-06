#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

// This enum is used to keep track of the different account types.
// Count is there to easily find out how many account types there are.
enum account_t { CHECKING, SAVINGS, COUNT };

class Account
{
public:
    // This static variable keeps track of the next account number to use when opening a new account.
    static int next_account_number;

    Account() : account_number(0), account_active(false), account_type(COUNT), account_owner("undefined"), account_balance(0) {}
    Account(int number, bool active, account_t type, std::string owner, double balance)
        : account_number(number), account_active(active), account_type(type), account_owner(owner), account_balance(balance) {}
    Account(account_t type, std::string owner, double balance = 0)
        : account_number(next_account_number), account_active(true), account_type(type), account_owner(owner), account_balance(balance)
        { next_account_number++; }

    // Getters and setters.
    int get_number() const { return account_number; }
    //void set_number(int number) { account_number = number; } // It is not be possible to change account number.
    bool is_active() const { return account_active; }
    void set_active(bool active) { account_active = active; }
    account_t get_type() const { return account_type; }
    void set_type(account_t type) { account_type = type; }
    std::string get_owner() const { return account_owner; }
    void set_owner(std::string owner) { account_owner = owner; }
    double get_balance() const { return account_balance; }
    void set_balance(double balance) { account_balance = balance; }
    bool deposit(double amount);
    bool withdraw(double amount);
    void print_info() const;

    // Operator overloading for conveniently reading and writing from and to streams
    friend std::ostream& operator<<(std::ostream& o, Account& a);
    friend std::istream& operator>>(std::istream& i, Account& a);
private:
    int account_number;
    bool account_active;
    account_t account_type;
    std::string account_owner;
    double account_balance;
};

#endif // ACCOUNT_H
