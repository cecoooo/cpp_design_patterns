#include "window.hpp"
#include "world.hpp"
#include "resource_factory.hpp"
#include "plugin_loader.hpp"
#include "resource_map.hpp"
#include <memory>
#include <iostream>
#include <thread>
#include <chrono>
#include "closest_point_strategy.hpp"
#include "greedy_strategy.hpp"


void fillMapWithResources(ResourceMap& map, ResourceFactory& resourceFactory)
{
    auto coal = resourceFactory.makeResource("coal", Vector2D(100, 200), 10, Color::BLUE, ShapeType::CIRCLE);
    auto iron = resourceFactory.makeResource("iron", Vector2D(10, 20), 15, Color::GREEN, ShapeType::HEXAGONE);
    auto stone = resourceFactory.makeResource("stone", Vector2D(60, 60), 20, Color::RED, ShapeType::SQUARE);
    auto wood = resourceFactory.makeResource("wood", Vector2D(1, 400), 25, Color::YELLOW, ShapeType::TRIANGLE);

    map.addResource(std::move(coal));
    map.addResource(std::move(iron));
    map.addResource(std::move(stone));
    map.addResource(std::move(wood));
}

std::shared_ptr<Player> createPlayerOnTheField(World& world)
{
    auto player = std::make_shared<Player>(Vector2D(200, 10));
    world.addPlayer(player);
    return player;
}


int main()
{
    auto window = std::make_shared<Window>(640, 480);
    World world(window);

    ResourceFactory resourceFactory;
    PluginLoader pluginLoader;
    ResourceMap map;

    pluginLoader.loadPlugin("./plugins/libcoal_plugin.so", resourceFactory);
    pluginLoader.loadPlugin("./plugins/libiron_plugin.so", resourceFactory);
    pluginLoader.loadPlugin("./plugins/libstone_plugin.so", resourceFactory);
    pluginLoader.loadPlugin("./plugins/libwood_plugin.so", resourceFactory);

    fillMapWithResources(map, resourceFactory);
    auto player = createPlayerOnTheField(world);
    
    while (window->isCreated()) 
    {
        window->refresh();
        world.displayAllResources(map.getResources());
        world.displayAllPlayers();
        player->gatherResources(10, map, std::make_unique<ClosestPointStrategy>());
    }
    return 0;
}