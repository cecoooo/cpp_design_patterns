#include "car.hpp"
#include <iostream>

Car::Car(const Engine& eng, std::vector<Tire> trs): 
engine(eng)
{
    tires.assign(trs.begin(), trs.end());
}

void Car::changeTires(std::vector<Tire> trs)
{
    tires.assign(trs.begin(), trs.end());
}

std::vector<Tire> Car::getTires() const
{
    return tires;
}

void Car::updateEngine(const Engine& engine)
{
    this->engine = engine;
}

Engine Car::getEngine() const
{
    return engine;
}