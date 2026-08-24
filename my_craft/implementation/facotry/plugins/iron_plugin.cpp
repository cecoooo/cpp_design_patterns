#include "resource_factory.hpp"
#include "iron.hpp"

#include <memory>

extern "C" void registerPlugin(ResourceFactory& factory)
{
    factory.registerMaker(
        "iron",
        [](const Vector2D& coordinates, int size, Color color, ShapeType shape)
            -> std::unique_ptr<Resource>
        {
            return std::make_unique<Iron>(coordinates, size, color, shape);
        });
}