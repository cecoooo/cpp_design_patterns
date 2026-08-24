#pragma once
#include "circle.hpp"
#include "rectangle.hpp"

class ShapeVisitor
{
public:
    ~ShapeVisitor()=default;
    virtual void visit(Circle& shape) = 0;
    virtual void visit(Rectangle& shape) = 0;
};