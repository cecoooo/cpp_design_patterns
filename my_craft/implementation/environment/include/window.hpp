#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "vector_2d.hpp"
#include "color.hpp"
#include "shape_type.hpp"

class Window
{
private:
    sf::RenderWindow window;
    sf::CircleShape createShape(int size, ShapeType shapeType);
    void fillColor(sf::CircleShape& shape, Color color);
    bool checkForCloseCommand();
public:
    Window(unsigned int width, unsigned int height);
    bool isCreated();
    void refresh();
    void draw(int size, ShapeType shapeType, Color color, Vector2D coords);
};