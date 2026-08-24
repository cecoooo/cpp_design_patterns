#pragma once

struct MoneyAdder {
    virtual ~MoneyAdder() = default;
    virtual void addMoney(long long wholePart, long centPart) = 0;
};
