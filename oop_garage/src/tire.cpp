#include "tire.hpp"

Tire::Tire(const std::string& tType) {
    if (tType == "cheep")
    {
        tireType = TireType::CHEEP;
    }
    else if(tType == "middle")
    {
        tireType = TireType::MIDDLE;
    }
    else if(tType == "expensive")
    {
        tireType = TireType::EXPENSIVE;
    }
    else
    {
        tireType = TireType::UNKNOWN;
    }
}

long double Tire::getPrice() const
{
    switch (tireType)
    {
    case TireType::CHEEP:
        return 100L;
        break;
    case TireType::MIDDLE:
        return 200L;
        break;
    case TireType::EXPENSIVE:
        return 300L;
        break;
    default:
        return 0L;
        break;
    }
}