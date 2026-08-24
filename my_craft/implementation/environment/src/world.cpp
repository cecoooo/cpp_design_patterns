#include "world.hpp"
#include <algorithm>

World::World(std::shared_ptr<Window> w): window(w){}

void World::displayAllResources(std::vector<std::shared_ptr<Resource>> resources)
{
    for(const auto& item : resources) 
    {
        window->draw(item->dimensions(), item->shape(), item->color(), item->position());
    }
}

void World::displayAllPlayers()
{
    for(const auto& item : players)
    {
        window->draw(15, item->shape(), item->color(), item->position());
    }
}

void World::addPlayer(std::shared_ptr<Player> player)
{
    players.push_back(player);
}

void World::removePlayer(std::shared_ptr<Player> player)
{
    players.erase(
        std::remove_if(players.begin(), players.end(),
            [&player](const std::shared_ptr<Player>& p) {
                return p == player;
            }),
        players.end()
    );
}