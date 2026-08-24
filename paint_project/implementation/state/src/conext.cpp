#include "context.hpp"

void Context::createState(std::unique_ptr<BaseState> state)
{
    this->state = std::move(state);
}

void Context::execute(std::shared_ptr<Shape> shape, std::shared_ptr<Window> window)
{
    state->executeAction(shape, window);
}