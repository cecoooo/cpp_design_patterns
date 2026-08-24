#pragma once
#include <vector>
#include <memory>
#include "window.hpp"
#include "resource.hpp"
#include "player.hpp"

class World
{
private:
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<Window> window;
public:
    World(std::shared_ptr<Window> w);
    void addPlayer(std::shared_ptr<Player>);
    void removePlayer(std::shared_ptr<Player>);
    void displayAllResources(std::vector<std::shared_ptr<Resource>> resources);
    void displayAllPlayers();
};
