#include "rotate_visitor.hpp"

void RotateVisitor::visit(Circle& shape)
{
    shape.rotation += 30;
}

void RotateVisitor::visit(Rectangle& shape)
{
    shape.rotation += 30;
}
