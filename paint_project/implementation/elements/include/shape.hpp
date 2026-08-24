#pragma once
#include <string>
#include <memory>
#include "color.hpp"
#include "window.hpp"
#include "vector_2d.hpp"

class ShapeVisitor;

class Shape
{
protected:
    Vector2D coords;
public:
    float rotation=0;
    Color color;
    Shape(Vector2D coordinates, Color col);
    Shape();
    virtual ~Shape();
    virtual void move(Vector2D dest)=0;
    virtual void draw(std::shared_ptr<Window> w)=0;
    virtual void rotate(float degrees)=0;
    virtual void scale(float percentage)=0;
    Vector2D coordinates() const;
    virtual void accept(std::shared_ptr<ShapeVisitor>)=0;