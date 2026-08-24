#include "move_command.hpp"

MoveCommand::MoveCommand(std::shared_ptr<Shape> sh, const Vector2D& dest)
: shape(sh), destination(dest), initial_location(sh->coordinates()){}

void MoveCommand::execute()
{
    shape->move(destination);
    counterExecution++;
}

void MoveCommand::undo()
{
    if(counterExecution > 0)
    {
        shape->move(initial_location);
        counterExecution--;
    }
}