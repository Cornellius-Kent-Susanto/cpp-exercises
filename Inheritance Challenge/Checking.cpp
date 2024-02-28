#include "Checking.h"

std::ostream &operator<<(std::ostream &os, const Checking &rhs)
{
    os << "[Checking : " << rhs.name << " : " << rhs.balance
       << "]";
    return os;
}
Checking::Checking(std::string name, double balance)
    : Account{name, balance}
{
}
bool Checking::withdraw(double amount)
{
    amount += 1.5;
    return Account::withdraw(amount);
}