#pragma once
#include "player.hpp"
#include <string>

class Garage
{
private:
    bool checkCarId(const Player& player, unsigned int carId);
public:
    void changeTires(const std::string& qualityOfTire, Player& player, unsigned int carId);
    void updateEngine(int vol, const int hp, Player& player, unsigned int carId);
};