#include "coal.hpp"

Coal::Coal(const Vector2D& coordinates, int sz, Color clr, ShapeType sht): 
    Resource(coordinates, sz, clr, sht){}

int Coal::dimensions() const
{
    return size;
}

Color Coal::color() const
{
    return shapeColor;
}

ShapeType Coal::shape() const
{
    return shapeType;
}

Vector2D Coal::position() const
{
    return coords;
}