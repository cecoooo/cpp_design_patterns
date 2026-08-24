#include "click_state.hpp"

void ClickState::executeAction(std::shared_ptr<Shape> shape, std::shared_ptr<Window> window)
{
    while(!window->catchLeftButtonClick())
    {
        shape->move(window->getMousePosition());
    }
}