#pragma once
#include "vector_2d.hpp"
#include "color.hpp"
#include "shape_type.hpp"
#include <memory>

class Resource
{
protected:
    int size;
    Color shapeColor;
    ShapeType shapeType;
    Vector2D coords;
public:
    Resource(const Vector2D& coordinates, int size, Color color, ShapeType shape);
    virtual ~Resource() = default;
    virtual int dimensions() const = 0;
    virtual Color color() const = 0;
    virtual ShapeType shape() const = 0;
    virtual Vector2D position() const = 0;
};