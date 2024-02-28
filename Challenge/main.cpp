// Section 15
// Challenge
#include <iostream>
#include <vector>

#include "Trust.h"
#include "Checking.h"
#include "Savings_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    vector<Trust> accounts{};
    accounts.push_back(Trust{"Kent", 190'000});
    accounts.push_back(Trust{"Bryant", 100'000});
    accounts.push_back(Trust{"Steve", 120'888});
    (accounts.at(1)).withdraw(1);
    (accounts.at(1)).withdraw(1);
    (accounts.at(1)).withdraw(1);
    display(accounts);
    deposit(accounts, 100);
    withdraw(accounts, 100);
    accounts.at(0) += accounts.at(1);
    cout << accounts.at(0);
    return 0;
}
