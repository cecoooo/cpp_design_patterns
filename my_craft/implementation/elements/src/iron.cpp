#include "iron.hpp"

Iron::Iron(const Vector2D& coordinates, int sz, Color clr, ShapeType sht): 
    Resource(coordinates, sz, clr, sht){}

int Iron::dimensions() const
{
    return size;
}

Color Iron::color() const
{
    return shapeColor;
}

ShapeType Iron::shape() const
{
    return shapeType;
}

Vector2D Iron::position() const
{
    return coords;
}