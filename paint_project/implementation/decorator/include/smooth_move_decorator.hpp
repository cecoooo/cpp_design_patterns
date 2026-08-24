#pragma once
#include <memory>
#include "shape_decorator.hpp"

class SmoothMoveDecorator: public ShapeDecorator
{
public:
    SmoothMoveDecorator(std::shared_ptr<Shape> shapePtr);
    void move(Vector2D dest) override;
};