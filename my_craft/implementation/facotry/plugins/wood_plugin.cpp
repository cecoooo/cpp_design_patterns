#include "resource_factory.hpp"
#include "wood.hpp"

#include <memory>

extern "C" void registerPlugin(ResourceFactory& factory)
{
    factory.registerMaker(
        "wood",
        [](const Vector2D& coordinates, int size, Color color, ShapeType shape)
            -> std::unique_ptr<Resource>
        {
            return std::make_unique<Wood>(coordinates, size, color, shape);
        });
}