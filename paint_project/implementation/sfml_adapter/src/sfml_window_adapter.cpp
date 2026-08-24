#include "sfml_window_adapter.hpp"
#include <stdexcept>
#include <iostream>

SfmlWindowAdapter::SfmlWindowAdapter(unsigned int len, unsigned int wid, std::string name): Window(len, wid, name)
{}

void SfmlWindowAdapter::startWindow()
{
    window.create(sf::VideoMode({length, width}), windowName); 
}

void SfmlWindowAdapter::stopWindow()
{
    window.close();
}

bool SfmlWindowAdapter::isOpen()
{
    return window.isOpen();
}

bool SfmlWindowAdapter::checkForCloseEvent()
{
    bool res = false;
    while (auto eventOpt = window.pollEvent())
    {
        if (eventOpt->is<sf::Event::Closed>())
        {
            res = true;
        }
    }
    return res;
}

void SfmlWindowAdapter::clear()
{
    window.clear(sf::Color::White);
}

void SfmlWindowAdapter::draw(Vector2D position, const std::vector<float>& sizes, Color col, ShapeType sht, float rotation)
{
    std::unique_ptr<sf::Shape> shape = determineShape(sht, sizes);
    shape->setFillColor(determineColor(col));
    shape->setPosition(position);
    shape->setRotation(sf::degrees(rotation));
    window.draw(*shape);
}

void SfmlWindowAdapter::refresh()
{
    window.display();
}

sf::Color SfmlWindowAdapter::determineColor(Color col)
{
    return sf::Color(col.r, col.g, col.b, col.a);
}

std::unique_ptr<sf::Shape> SfmlWindowAdapter::determineShape(ShapeType sht, const std::vector<float>& sizes)
{
    if(sizes.size() == 0)
    {
        throw std::runtime_error("Size not given!");
    }
    else if(sizes.size() < 2 && (sht == ShapeType::POLYGON || sht == ShapeType::RECTANGLE))
    {
        if(sht == ShapeType::POLYGON)
        {
            throw std::runtime_error("Polygon number of sizes not given!");
        }
        if(sht == ShapeType::RECTANGLE)
        {
            throw std::runtime_error("Rectangle sides not given!");
        }
    }
    else if(sizes[1] < 3 && sht == ShapeType::POLYGON)
    {
        throw std::runtime_error("Polygon must have at least 3 sides.");
    }
    switch(sht)
    {
        case CIRCLE:
            return std::make_unique<sf::CircleShape>(sizes[0]);
            break;
        case RECTANGLE:
            return std::make_unique<sf::RectangleShape>(sf::Vector2f{sizes[0], sizes[1]});
            break;
        case TRIANGLE:
            return std::make_unique<sf::CircleShape>(sizes[0], 3);
            break;
        case SQUARE:
            return std::make_unique<sf::CircleShape>(sizes[0], 4);
            break;
    }
    return std::make_unique<sf::CircleShape>(sizes[0], static_cast<std::size_t>(sizes[1]));
}

std::optional<Vector2D> SfmlWindowAdapter::checkForButtonPressed(sf::Mouse::Button typeOfButton)
{
    while (auto eventOpt = window.pollEvent())
    {
        if (eventOpt->is<sf::Event::MouseButtonPressed>())
        {
            std::cout << "button pressed" << std::endl;
            const auto* mouse = eventOpt->getIf<sf::Event::MouseButtonPressed>();
            if (mouse && mouse->button == typeOfButton)
            {
                std::cout << "button is left" << std::endl;
                return Vector2D(mouse->position.x, mouse->position.y);
            }
        }
    }
    return std::nullopt;
}

std::optional<Vector2D> SfmlWindowAdapter::catchLeftButtonClick()
{
    return checkForButtonPressed(sf::Mouse::Button::Left);
}

std::optional<Vector2D> SfmlWindowAdapter::catchRightButtonClick()
{
    return checkForButtonPressed(sf::Mouse::Button::Right);
}

std::optional<Vector2D> SfmlWindowAdapter::catchMiddleButtonClick()
{
    return checkForButtonPressed(sf::Mouse::Button::Middle);
}

Vector2D SfmlWindowAdapter::getMousePosition()
{
    sf::Vector2i mousePosWindow = sf::Mouse::getPosition(window);
    return Vector2D(mousePosWindow.x, mousePosWindow.y);
}