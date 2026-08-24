#include "player.hpp"

Player::Player(const std::string& name): 
    name(name){}
    

long double Player::getBankBalance()
{
    return money;
}
    
void Player::addMoneyToAccount(long double sum)
{
    money+=sum;
}

std::string Player::getName() const
{
    return name;
}

void Player::addCar(std::shared_ptr<Car> car)
{
    cars.push_back(car);
}

void Player::removeCar(unsigned int carId)
{
    if (carId < cars.size())
    {
        cars.erase(cars.begin() + carId);
    }
}

std::vector<std::shared_ptr<Car>> Player::getAllCars() const
{
    return cars;
}

void Player::subtractMoneyFromAccount(long double sum)
{
    money-=sum;
}