#ifndef Trust_H
#define Trust_H
#include "Savings_Account.h"

class Trust : public Savings_Account
{
private:
    short numOfwthw;
    friend std::ostream &operator<<(std::ostream &os, const Trust &rhs);

public:
    Trust(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif