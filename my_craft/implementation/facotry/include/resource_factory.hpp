#pragma once
#include <memory>
#include <unordered_map>
#include <functional>
#include <string>
#include "resource.hpp"
#include "vector_2d.hpp"
#include "color.hpp"
#include "shape_type.hpp"

using ResourceMaker = std::function<std::unique_ptr<Resource>(const Vector2D& coordinates, 
    int size, Color color, ShapeType shape)>;


class ResourceFactory
{
public:
    std::unique_ptr<Resource> makeResource(const std::string& type, const Vector2D& coordinates, 
        int size, Color color, ShapeType shape) const;
    void registerMaker(const std::string& type, ResourceMaker maker);
private:
    std::unordered_map<std::string, ResourceMaker> makers;
};