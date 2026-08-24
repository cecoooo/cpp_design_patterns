#pragma once
#include "resource.hpp"
#include <vector>
#include <memory>

class ResourceMap
{
private:
    std::vector<std::shared_ptr<Resource>> resources;
public:
    std::vector<std::shared_ptr<Resource>> getResources() const;
    void addResource(std::shared_ptr<Resource>);
    void removeResource(std::shared_ptr<Resource>);
};