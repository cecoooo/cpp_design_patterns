#pragma once
#include <memory>
#include "command.hpp"
#include "shape.hpp"
#include "vector_2d.hpp"

class MoveCommand: public Command
{
private:
    std::shared_ptr<Shape> shape;
    Vector2D destination;
    Vector2D initial_location;
public:
    MoveCommand(std::shared_ptr<Shape> sh, const Vector2D& dest);
    void execute() override;
    void undo() override;
};