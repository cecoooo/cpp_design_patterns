#include "race.hpp"
#include <random>
#include <iostream>

    
Race::Race(const std::string& name, long double award):raceName(name), moneyAward(award){}

Race::~Race()
{
    allTimeRegister.clear();
}

std::string Race::getName() const
{
    return raceName;
}

void Race::startRace(std::vector<std::pair<std::shared_ptr<Player>, int>> conts)
{
    for (size_t i = 0; i < conts.size(); i++)
    {
        auto it = allTimeRegister.find(conts[i].first);
        if (it == allTimeRegister.end())
        {
            allTimeRegister[conts[i].first] = 1;
        }
    }
    contenders.assign(conts.begin(), conts.end());
    determineWinner();
    winner->addMoneyToAccount(moneyAward);
    allTimeRegister[winner]++;
    endRace();
}

void Race::determineWinner()
{
    std::vector<int> winner_indexes;
    float maxScore = 0;
    for (size_t i = 0; i < contenders.size(); i++)
    {
        float score = determineScore(contenders[i]);
        std::cout << contenders[i].first->getName() << " Score: " << score << std::endl;
        if(score > maxScore)
        {
            winner_indexes.clear();
            maxScore = score;
            winner_indexes.push_back(i);
        }
        else if(score == maxScore)
        {
            winner_indexes.push_back(i);
        }
    }
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> dist(0, winner_indexes.size()-1);

    int picked = winner_indexes[dist(gen)];

    std::cout << "Winner Score: " << maxScore << std::endl;
    winner = contenders[picked].first;
}

long double Race::determineScore(std::pair<std::shared_ptr<Player>, int> contender)
{
    auto cars = contender.first->getAllCars();
    auto tires = cars[contender.second]->getTires();

    long double tirePrice = std::accumulate(
        tires.begin(), tires.end(), 0.0L,
        [](long double sum, const Tire& t) { return sum + t.getPrice(); }
    );

    return allTimeRegister[contender.first] * 
                        (contender.first->getAllCars()[contender.second]->getEngine().getPower() +
                        contender.first->getAllCars()[contender.second]->getEngine().getVolumeInCubicCm()) + tirePrice;

}

void Race::updateAward(long double sum)
{
    moneyAward+=sum;
}

long double Race::showAward() const
{
    return moneyAward;
}

std::shared_ptr<Player> Race::getLastWinner() const
{
    return winner;
}

void  Race::endRace()
{
    contenders.clear();
}