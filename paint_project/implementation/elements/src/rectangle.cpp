#include "rectangle.hpp"
#include <cmath>
#include "shape_visitor.hpp"

Rectangle::Rectangle(Vector2D coordinates, Color col, float len, float width): 
    Shape(coordinates, col), shape(ShapeType::RECTANGLE), length(len), width(width){}

void Rectangle::draw(std::shared_ptr<Window> window)
{
    window->draw(coords, {length, width}, color, shape, rotation);
    window->refresh();
}

void Rectangle::rotate(float degrees)
{
    rotation += degrees;
}

void Rectangle::scale(float percentage)
{
    float increaseValueLen = (std::fabs(percentage)/100)*length;
    float increaseValueWid = (std::fabs(percentage)/100)*width;
    if(percentage >= 0)
    {
        length += increaseValueLen;
        width += increaseValueWid;
    }
    else
    {
        if(std::fabs(percentage) > 100)
        {
            length = 0;
            width = 0;
        }
        else
        {
            length -= increaseValueLen;
            width -= increaseValueWid;
        }
    }
}

void Rectangle::move(Vector2D dest)
{
    coords = dest;
}

void Rectangle::accept(std::shared_ptr<ShapeVisitor> visitor)
{
    visitor->visit(*this);
}