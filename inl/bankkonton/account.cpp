#include "account.h"

#include <iostream>
#include <iomanip>

bool Account::deposit(double amount)
{
    if(amount > 0) {
        account_balance += amount;
        return true;
    } else {
        return false;
    }
}

bool Account::withdraw(double amount)
{
    if(amount > 0 && amount <= account_balance) {
        account_balance -= amount;
        return true;
    } else {
        return false;
    }
}

void Account::print_info() const
{
    std::cout << std::setw(10) << "#: " << account_number << std::endl;
    std::cout << std::setw(10) << "Type: ";
    switch(account_type) {
    case SAVINGS:
        std::cout << "Savings account" << std::endl;
        break;
    case CHECKING:
        std::cout << "Checking account" << std::endl;
        break;
    default:
        break;
    }
    std::cout << std::setw(10) << "Owner: " << account_owner << std::endl;
    std::cout << std::setw(10) << "Balance: " << std::fixed << std::setprecision(2) << account_balance << std::endl;
}

std::ostream& operator<<(std::ostream& o, Account& a)
{
    o << a.get_number() << "\t"
      << std::setw(5) << a.get_type() << "\t"
      << a.get_owner() << "\t"
      << a.get_balance()
      << std::endl;
    return o;
}

std::istream& operator>>(std::istream& i, Account& a)
{
    int number;
    int type;
    std::string owner;
    double balance;

    i >> number >> type >> owner >> balance;
    a.account_number = number;
    a.account_type = static_cast<account_t>(type);
    a.account_owner = owner;
    a.account_balance = balance;
    return i;
}
