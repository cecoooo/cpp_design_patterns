#pragma once
#include "shape_visitor.hpp"

class RotateVisitor: public ShapeVisitor
{
public:
    void visit(Circle& shape) override;
    void visit(Rectangle& shape) override;
};