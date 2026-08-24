#include "garage.hpp"    
#include <iostream>

void Garage::changeTires(const std::string& qualityOfTire, Player& player, unsigned int carId)
{
    if(!checkCarId(player, carId))
    {
        return;
    }
    std::vector<Tire> newTires;
    for (size_t i = 0; i < 4; i++)
    {
        newTires.push_back(Tire(qualityOfTire));
    }
    player.getAllCars()[carId]->changeTires(newTires);
    player.subtractMoneyFromAccount(player.getAllCars()[carId]->getTires()[0].getPrice() *4);
}

void Garage::updateEngine(int vol, const int hp, Player& player, unsigned int carId)
{
    if(!checkCarId(player, carId))
    {
        return;
    }
    Engine engine(vol, hp);
    player.getAllCars()[carId]->updateEngine(engine);
    player.subtractMoneyFromAccount(3000);
}

bool Garage::checkCarId(const Player& player, unsigned int carId)
{
    if(carId < player.getAllCars().size())
    {
        return true;
    }
    return false;
}