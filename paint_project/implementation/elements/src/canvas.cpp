    #include "canvas.hpp"
#include <algorithm>

Canvas::Canvas(){}

void Canvas::addShape(const std::shared_ptr<Shape> shape)
{
    shapes.push_back(shape);
    fixCoords();
}

void Canvas::removeShape(const std::shared_ptr<Shape> shape)
{
    shapes.erase(
        std::remove_if(shapes.begin(), shapes.end(),
            [&shape](const std::shared_ptr<Shape>& shp) { return shp == shape; }
        ),
        shapes.end()
    );
    fixCoords();
}

void Canvas::fixCoords()
{
    float newX = 0;
    float newY = 0;
    float div = 0;
    for (auto& ptr : shapes) {
        newX += ptr->coordinates().x();
        newY += ptr->coordinates().y();
        div++;
    }         
    if(div > 0)
    {
        coords = {newX/div, newY/div};
    }
    else
    {
        coords = {0, 0};
    }
}

void Canvas::draw(std::shared_ptr<Window> window)
{
    for (auto& ptr : shapes) {
        ptr->draw(window);
    }
}

void Canvas::rotate(float degrees)
{
    for (auto& ptr : shapes) {
        ptr->rotate(degrees);
    }
}

void Canvas::scale(float percentage)
{
    for (auto& ptr : shapes) {
        ptr->scale(percentage);
    }
}

void Canvas::move(Vector2D dest)
{
    for (auto& ptr : shapes) {
        ptr->move(dest);
    }
    fixCoords();
}