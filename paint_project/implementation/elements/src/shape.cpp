#include "shape.hpp"

Shape::Shape(Vector2D coordinates, Color col): coords(coordinates), color(col)
{}

Shape::Shape(): coords(0, 0), color(WHITE){}

Shape::~Shape(){}

Vector2D Shape::coordinates() const
{
    return coords;
}