#include "circle.hpp"
#include <cmath>
#include "shape_visitor.hpp"

Circle::Circle(Vector2D coordinates, Color col, float r): Shape(coordinates, col), shape(ShapeType::CIRCLE), radius(r){}

void Circle::draw(std::shared_ptr<Window> window)
{
    window->draw(coords, {radius}, color, shape, rotation);
    window->refresh();
}

void Circle::rotate(float degrees)
{
    rotation += degrees;
}

void Circle::scale(float percentage)
{
    float increaseValue = (std::fabs(percentage)/100)*radius;
    if(percentage >= 0)
    {
        radius += increaseValue;
    }
    else
    {
        if(std::fabs(percentage) > 100)
        {
            radius = 0;
        }
        else
        {
            radius -= increaseValue;
        }
    }
}

void Circle::move(Vector2D dest)
{
    coords = dest;
}

void Circle::accept(std::shared_ptr<ShapeVisitor> visitor)
{
    visitor->visit(*this);
}