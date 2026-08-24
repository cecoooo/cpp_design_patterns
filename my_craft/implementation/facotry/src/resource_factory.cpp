#include "resource_factory.hpp"


std::unique_ptr<Resource> ResourceFactory::makeResource(const std::string& type, const Vector2D& coordinates, 
        int size, Color color, ShapeType shape) const
{
    auto maker = makers.at(type);
    return maker(coordinates, size, color, shape);
}

void ResourceFactory::registerMaker(const std::string& type, ResourceMaker maker)
{
    makers[type] = maker;
}