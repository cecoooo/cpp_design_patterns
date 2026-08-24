#pragma once
#include "player.hpp"
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

class Race
{
private:
    std::unordered_map<std::shared_ptr<Player>, long double> allTimeRegister;
    std::string raceName;
    std::vector<std::pair<std::shared_ptr<Player>, int>> contenders;
    long double moneyAward;
    void determineWinner();
    long double determineScore(std::pair<std::shared_ptr<Player>, int> contender);
    void endRace();
    std::shared_ptr<Player> winner;
public:
    Race(const std::string& name, long double award);
    ~Race();
    void startRace(std::vector<std::pair<std::shared_ptr<Player>, int>> conts);
    std::shared_ptr<Player> getLastWinner() const;
    std::string getName() const;
    void updateAward(long double sum);
    long double showAward() const;
};