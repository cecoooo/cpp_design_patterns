#include "player.hpp"
#include <thread>
#include <chrono>
#include <iostream>

Player::Player(Vector2D coordinates)
{
    shapeType = ShapeType::PLAYER;
    shapeColor = Color::WHITE;
    coords = coordinates;
}

Vector2D Player::position() const
{
    return coords;
}

Color Player::color() const
{
    return shapeColor;
}

ShapeType Player::shape() const
{
    return shapeType;
}

void Player::makeStep(Vector2D destination)
{
    if (coords.x() < destination.x())
    {
        coords = Vector2D(coords.x() + 1, coords.y());
    }
    else if (coords.x() > destination.x())
    {
        coords = Vector2D(coords.x() - 1, coords.y());
    }

    if (coords.y() < destination.y())
    {
        coords = Vector2D(coords.x(), coords.y() + 1);
    }
    else if (coords.y() > destination.y())
    {
        coords = Vector2D(coords.x(), coords.y() - 1);
    }
}

void Player::gatherResources(int speed, ResourceMap& map, const std::unique_ptr<Strategy> strategy)
{
    auto res = strategy->targetResource(map.getResources(), coords);
    if (!res) return;

    if (coords != res->position())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
        makeStep(res->position());
    }
    else
    {
        map.removeResource(res);
        resources.push_back(res);
    }
}