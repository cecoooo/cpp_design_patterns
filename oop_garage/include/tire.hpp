#pragma once
#include <string>


enum TireType{
    CHEEP,
    MIDDLE,
    EXPENSIVE,
    UNKNOWN
};


class Tire
{
private:
    TireType tireType;
public:
    Tire(const std::string& tType);
    long double getPrice() const;
};