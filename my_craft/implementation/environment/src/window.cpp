#include "window.hpp"

Window::Window(unsigned int width, unsigned int height) 
    : window(sf::VideoMode({width, height}), "My Craft") {}

bool Window::isCreated()
{
    return window.isOpen();
}

void Window::refresh()
{
    if (checkForCloseCommand())
    {
        window.close();
    }
    window.clear();
}

sf::CircleShape Window::createShape(int size, ShapeType shapeType)
{
    switch (shapeType)
    {
    case ShapeType::CIRCLE:
        return sf::CircleShape(size);
        break;
    case ShapeType::TRIANGLE:
        return sf::CircleShape(size, 3);
        break;
    case ShapeType::SQUARE:
        return sf::CircleShape(size, 4);
        break;
    case ShapeType::HEXAGONE:
        return sf::CircleShape(size, 6);
        break;
    case ShapeType::PLAYER:
        return sf::CircleShape(size);
        break;
    default:
        return sf::CircleShape(size);
        break;
    }
}

void Window::fillColor(sf::CircleShape& shape, Color color)
{
    switch (color)
    {
    case Color::RED:
        shape.setFillColor(sf::Color::Red);
        break;
    case Color::GREEN:
        shape.setFillColor(sf::Color::Green);
        break;
    case Color::BLUE:
        shape.setFillColor(sf::Color::Blue);
        break;
    case Color::YELLOW:
        shape.setFillColor(sf::Color::Yellow);
        break;
    case Color::WHITE:
        shape.setFillColor(sf::Color::White);
        break;
    }
}

void Window::draw(int size, ShapeType shapeType, Color color, Vector2D coords)
{
    sf::CircleShape shape = createShape(size, shapeType);
    fillColor(shape, color);
    shape.setPosition({static_cast<float>(coords.x()), static_cast<float>(coords.y())});
    window.draw(shape);
    window.display();
}

bool Window::checkForCloseCommand()
{
    bool res = false;
    while (auto eventOpt = window.pollEvent()) {
        if (eventOpt->is<sf::Event::Closed>()) {
            res = true;
        }
    }
    return res;
}
