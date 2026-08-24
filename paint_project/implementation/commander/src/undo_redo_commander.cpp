#include "undo_redo_commander.hpp"

void UndoRedoCommander::addCommand(std::unique_ptr<Command> comm)
{
    comm->execute();

    while (!redoStack.empty())
        redoStack.pop();
        
    undoStack.push(std::move(comm));
}

void UndoRedoCommander::undo()
{
    if(!undoStack.empty())
    {
        undoStack.top()->undo();
        redoStack.push(std::move(undoStack.top()));
        undoStack.pop();
    }
}

void UndoRedoCommander::redo()
{
    if(!redoStack.empty())
    {
        redoStack.top()->execute();
        undoStack.push(std::move(redoStack.top()));
        redoStack.pop();
    }
}