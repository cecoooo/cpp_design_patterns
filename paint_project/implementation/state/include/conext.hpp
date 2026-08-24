#pragma once
#include "base_state.hpp"
#include "shape.hpp"
#include <memory>

class Context
{
private:
    std::unique_ptr<BaseState> state;
public:
    void createState(std::unique_ptr<BaseState>);
    void execute(std::shared_ptr<Shape> shape, std::shared_ptr<Window> window);
};