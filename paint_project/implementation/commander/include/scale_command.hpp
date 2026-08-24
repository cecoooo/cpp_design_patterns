#pragma once
#include <memory>
#include "command.hpp"
#include "shape.hpp"

class ScaleCommand: public Command
{
private:
    std::shared_ptr<Shape> shape;
    float percentage;
public:
    ScaleCommand(std::shared_ptr<Shape> sh, float per);
    void execute() override;
    void undo() override;
};