#pragma once
#include <memory>
#include "shape.hpp"

class ShapeDecorator: public Shape
{
protected:
    std::shared_ptr<Shape> decoratedShape;
public:
    ShapeDecorator(std::shared_ptr<Shape> shapePtr);
    virtual ~ShapeDecorator();
    void move(Vector2D dest) override;
    void draw(std::shared_ptr<Window> w) override;
    void rotate(float degrees) override;
    void scale(float percentage) override;
    void accept(std::shared_ptr<ShapeVisitor>) override {};
};