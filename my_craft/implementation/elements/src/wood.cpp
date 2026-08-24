#include "wood.hpp"

Wood::Wood(const Vector2D& coordinates, int sz, Color clr, ShapeType sht): 
    Resource(coordinates, sz, clr, sht){}

int Wood::dimensions() const
{
    return size;
}

Color Wood::color() const
{
    return shapeColor;
}

ShapeType Wood::shape() const
{
    return shapeType;
}

Vector2D Wood::position() const
{
    return coords;
}