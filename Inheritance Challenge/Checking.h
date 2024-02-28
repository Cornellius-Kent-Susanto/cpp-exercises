#ifndef Checking_H
#define Checking_H
#include "Account.h"

class Checking : public Account
{
private:
    friend std::ostream &operator<<(std::ostream &os, const Checking &rhs);
    static constexpr const char *ptr{"No name"};

public:
    Checking(std::string name = ptr, double balance = 0.0);
    bool withdraw(double amount);
};
#endif