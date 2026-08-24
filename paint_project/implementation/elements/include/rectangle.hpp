#pragma once
#include "shape.hpp"
#include "shape_type.hpp"

class Rectangle: public Shape
{
private:
    ShapeType shape;
    float length;
    float width;
public:
    Rectangle(Vector2D coordinates, Color col, float len, float width);
    void move(Vector2D dest) override;
    void draw(std::shared_ptr<Window> w) override;
    void rotate(float degrees) override;
    void scale(float percentage) override;
    void accept(std::shared_ptr<ShapeVisitor>) override;
};