#pragma once
#include "money_adder.hpp"
#include "money_subtractor.hpp"
#include <string>

class BankAccount: public MoneyAdder, public MoneySubtractor
{
private:
    long long cents_amount = 0;
public:
    BankAccount() = default;
    void addMoney(long long wholePart, long centPart) override;
    void subtractMoney(long long wholePart, long centPart) override;
    std::string showBalance() const;
    long long getBalance() const;
};