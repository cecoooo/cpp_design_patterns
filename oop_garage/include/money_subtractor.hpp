#pragma once

struct MoneySubtractor {
    virtual ~MoneySubtractor() = default;
    virtual void subtractMoney(long long wholePart, long centPart) = 0;
};