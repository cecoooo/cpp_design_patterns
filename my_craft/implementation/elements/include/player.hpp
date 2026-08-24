#pragma once
#include <vector>
#include <memory>
#include "vector_2d.hpp"
#include "resource.hpp"
#include "color.hpp"
#include "shape_type.hpp"
#include "resource_map.hpp"
#include "strategy.hpp"

class Player
{
private:
    std::vector<std::shared_ptr<Resource>> resources;
    Color shapeColor;
    ShapeType shapeType;
    Vector2D coords;
    void makeStep(Vector2D destination);
public:
    Player(Vector2D coords);
    Color color() const;
    ShapeType shape() const;
    Vector2D position() const;
    void gatherResources(int speed, ResourceMap& map, const std::unique_ptr<Strategy> strategy);
};