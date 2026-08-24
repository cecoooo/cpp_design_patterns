#pragma once
#include <cstdint>

class Command
{
protected:
    uint16_t counterExecution=0;
public:
    virtual ~Command()=default;
    virtual void execute()=0;
    virtual void undo()=0;
};