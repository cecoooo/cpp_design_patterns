#include "stone.hpp"

Stone::Stone(const Vector2D& coordinates, int sz, Color clr, ShapeType sht): 
    Resource(coordinates, sz, clr, sht){}

int Stone::dimensions() const
{
    return size;
}

Color Stone::color() const
{
    return shapeColor;
}

ShapeType Stone::shape() const
{
    return shapeType;
}

Vector2D Stone::position() const
{
    return coords;
}