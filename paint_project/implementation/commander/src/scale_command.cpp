#include "scale_command.hpp"

ScaleCommand::ScaleCommand(std::shared_ptr<Shape> sh, float per)
: shape(sh), percentage(per){}

void ScaleCommand::execute()
{
    shape->scale(percentage);
    counterExecution++;
}

void ScaleCommand::undo()
{
    if(counterExecution > 0)
    {
        shape->scale(-percentage);
        counterExecution--;
    }
}