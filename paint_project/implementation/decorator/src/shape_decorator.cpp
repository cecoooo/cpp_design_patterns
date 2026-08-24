#include "shape_decorator.hpp"

ShapeDecorator::ShapeDecorator(std::shared_ptr<Shape> shapePtr): decoratedShape(shapePtr){}

ShapeDecorator::~ShapeDecorator(){}

void ShapeDecorator::draw(std::shared_ptr<Window> window)
{
    decoratedShape->draw(window);
}

void ShapeDecorator::rotate(float degrees)
{
    decoratedShape->rotate(degrees);
}

void ShapeDecorator::scale(float percentage)
{
    decoratedShape->scale(percentage);
}

void ShapeDecorator::move(Vector2D dest)
{
    decoratedShape->move(dest);
}