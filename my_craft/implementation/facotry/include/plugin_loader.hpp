#pragma once

#include <string>
#include <vector>
#include "resource_factory.hpp"

class PluginLoader
{
public:
    ~PluginLoader();

    void loadPlugin(const std::string& path, ResourceFactory& factory);

private:
    std::vector<void*> handles;
};