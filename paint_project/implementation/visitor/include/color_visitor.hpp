#pragma once
#include "shape_visitor.hpp"
#include "color.hpp"

class ColorVisitor: public ShapeVisitor
{
public:
    void visit(Circle& shape) override;
    void visit(Rectangle& shape) override;
};