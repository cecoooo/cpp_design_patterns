#pragma once
#include "shape.hpp"
#include "shape_type.hpp"

class Circle: public Shape
{
private:
    ShapeType shape;
    float radius;
public:
    Circle(Vector2D coordinates, Color col, float r);
    void move(Vector2D dest) override;
    void draw(std::shared_ptr<Window> w) override;
    void rotate(float degrees) override;
    void scale(float percentage) override;
    void accept(std::shared_ptr<ShapeVisitor>) override;
};