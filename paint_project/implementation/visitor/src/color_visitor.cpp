#include "color_visitor.hpp"
#include "color.hpp"

void ColorVisitor::visit(Circle& shape)
{
    shape.color = BLACK;
}

void ColorVisitor::visit(Rectangle& shape)
{
    shape.color = BLACK;
}