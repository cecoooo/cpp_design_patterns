#pragma once
#include "engine.hpp"
#include "tire.hpp"
#include <utility>
#include <vector>

class Car
{
private:
    std::vector<Tire> tires;
    Engine engine;
public:
    Car(const Engine& eng, std::vector<Tire> tires);
    void changeTires(std::vector<Tire> tires);
    std::vector<Tire> getTires() const;
    void updateEngine(const Engine& engine);
    Engine getEngine() const;
};