#include "resource_factory.hpp"
#include "coal.hpp"

#include <memory>

extern "C" void registerPlugin(ResourceFactory& factory)
{
    factory.registerMaker(
        "coal",
        [](const Vector2D& coordinates, int size, Color color, ShapeType shape)
            -> std::unique_ptr<Resource>
        {
            return std::make_unique<Coal>(coordinates, size, color, shape);
        });
}