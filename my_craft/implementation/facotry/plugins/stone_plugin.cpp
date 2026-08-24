#include "resource_factory.hpp"
#include "stone.hpp"

#include <memory>

extern "C" void registerPlugin(ResourceFactory& factory)
{
    factory.registerMaker(
        "stone",
        [](const Vector2D& coordinates, int size, Color color, ShapeType shape)
            -> std::unique_ptr<Resource>
        {
            return std::make_unique<Stone>(coordinates, size, color, shape);
        });
}