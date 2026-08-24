#pragma once
#include <vector>
#include <memory>
#include "shape.hpp"
#include "shape_type.hpp"

class Canvas: public Shape
{
private:
    std::vector<std::shared_ptr<Shape>> shapes;
    void fixCoords();
public:
    Canvas();
    void addShape(const std::shared_ptr<Shape> shape);
    void removeShape(const std::shared_ptr<Shape> shape);
    void move(Vector2D dest) override;
    void draw(std::shared_ptr<Window> w) override;
    void rotate(float degrees) override;
    void scale(float percentage) override;
    void accept(std::shared_ptr<ShapeVisitor>) override {};
};