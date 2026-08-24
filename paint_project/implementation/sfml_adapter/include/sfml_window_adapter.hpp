#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "window.hpp"

class SfmlWindowAdapter: public Window
{
private:
    sf::RenderWindow window;
    sf::Color determineColor(Color col);
    std::unique_ptr<sf::Shape> determineShape(ShapeType sht, const std::vector<float>& sizes);
    std::optional<Vector2D> checkForButtonPressed(sf::Mouse::Button typeOfButton);
public:
    SfmlWindowAdapter(unsigned int len, unsigned int wid, std::string name);
    void startWindow() override;
    void stopWindow() override;
    bool isOpen() override;
    bool checkForCloseEvent() override;
    void clear() override;
    void draw(Vector2D position, const std::vector<float>& sizes, Color col, ShapeType sht, float rotation) override;
    void refresh() override;
    std::optional<Vector2D> catchLeftButtonClick() override;
    std::optional<Vector2D> catchRightButtonClick() override;
    std::optional<Vector2D> catchMiddleButtonClick() override;
    Vector2D getMousePosition() override;
};