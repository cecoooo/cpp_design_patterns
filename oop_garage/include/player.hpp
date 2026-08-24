#pragma once
#include "car.hpp"
#include <string>
#include <vector>
#include <memory>

class Player
{
private:
    std::string name;
    long double money;
    std::vector<std::shared_ptr<Car>> cars;
public:
    Player(const std::string& name);
    long double getBankBalance();
    void addMoneyToAccount(long double sum);
    std::string getName() const;
    void addCar(std::shared_ptr<Car> car);
    void removeCar(unsigned int carId);
    std::vector<std::shared_ptr<Car>> getAllCars() const;
    void subtractMoneyFromAccount(long double sum);
};
