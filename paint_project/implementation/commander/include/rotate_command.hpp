#pragma once
#include <memory>
#include "command.hpp"
#include "shape.hpp"

class RotateCommand: public Command
{
private:
    std::shared_ptr<Shape> shape;
    float degrees;
public:
    RotateCommand(std::shared_ptr<Shape> sh, float deg);
    void execute() override;
    void undo() override;
};