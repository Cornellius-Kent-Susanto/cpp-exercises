#include "Trust.h"

Trust::Trust(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, numOfwthw{0}
{
}

bool Trust::deposit(double amount)
{
    if (amount >= 5000)
    {
        this->balance += 50;
    }
    return Savings_Account::deposit(amount);
}

bool Trust::withdraw(double amount)
{
    if (Trust::numOfwthw > 2)
    {
        return false;
    }
    if (Savings_Account::withdraw(amount))
    {
        Trust::numOfwthw++;
        return true;
    }
    return false;
}
std::ostream &operator<<(std::ostream &os, const Trust &rhs)
{
    os << "[Trust : " << rhs.name << " : " << rhs.balance << " , " << rhs.int_rate << "]";
    return os;
}