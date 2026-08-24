#pragma once
#include "resource.hpp"
#include "vector_2d.hpp"
#include "color.hpp"
#include "shape_type.hpp"

class Stone: public Resource
{
public:
    Stone(const Vector2D& coordinates, int size, Color color, ShapeType shape);
    int dimensions() const override;
    Color color() const override;
    ShapeType shape() const override;
    Vector2D position() const override;
};