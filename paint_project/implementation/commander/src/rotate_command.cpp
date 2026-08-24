#include "rotate_command.hpp"

RotateCommand::RotateCommand(std::shared_ptr<Shape> sh, float deg)
: shape(sh), degrees(deg){}

void RotateCommand::execute()
{
    shape->rotate(degrees);
    counterExecution++;
}

void RotateCommand::undo()
{
    if(counterExecution > 0)
    {
        shape->rotate(-degrees);
        counterExecution--;
    }
}