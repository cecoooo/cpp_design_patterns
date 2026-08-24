#pragma once
#include "base_state.hpp"

class MoveState: BaseState
{
public:
    void executeAction(std::shared_ptr<Shape> shape, std::shared_ptr<Window> window) override;
};