#include "resource.hpp"

Resource::Resource(const Vector2D& coordinates, int sz, Color clr, ShapeType sht): 
    coords(coordinates), size(sz), shapeColor(clr), shapeType(sht){}