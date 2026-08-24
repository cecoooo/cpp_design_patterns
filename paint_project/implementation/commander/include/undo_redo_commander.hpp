#pragma once
#include <memory>
#include <stack>
#include "command.hpp"

class UndoRedoCommander
{
private:
    std::stack<std::unique_ptr<Command>> undoStack;
    std::stack<std::unique_ptr<Command>> redoStack;
public:
    void addCommand(std::unique_ptr<Command>);
    void undo();
    void redo();
};
