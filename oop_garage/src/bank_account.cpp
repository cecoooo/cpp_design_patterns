#include "bank_account.hpp"
#include <iostream>


void BankAccount::subtractMoney(long long wholePart, long centPart)
{
    if (wholePart < 0 || centPart < 0)
    {
        std::cerr << "Negative value amount could not be used to substract money" << std::endl;
    }
    else if(centPart > 99)
    {
        std::cerr << "Cent part must be in range 0-99" << std::endl;
    }
    else
    {
        cents_amount -= wholePart*100 + centPart;
    }
}

void BankAccount::addMoney(long long wholePart, long centPart)
{
    if (wholePart < 0 || centPart < 0)
    {
        std::cerr << "Negative value amount could not be used to add money" << std::endl;
    }
    else if(centPart > 99)
    {
        std::cerr << "Cent part must be in range 0-99" << std::endl;
    }
    else
    {
        cents_amount += wholePart*100 + centPart;
    }
}


std::string BankAccount::showBalance() const
{
    return std::to_string(cents_amount).insert(std::to_string(cents_amount).length()-2, ".");
}

long long BankAccount::getBalance() const
{
    return cents_amount;
}