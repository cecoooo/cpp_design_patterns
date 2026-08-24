#pragma once
#include "shape.hpp"
#include "window.hpp"

class BaseState
{
public:
    virtual ~BaseState()=default;
    virtual void executeAction(std::shared_ptr<Shape> shape, std::shared_ptr<Window> window)=0;
};


// case: click on a shape -> move the shape with cursor -> click again and shape stop moving with cursor