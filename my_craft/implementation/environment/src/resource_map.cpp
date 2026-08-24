#include "resource_map.hpp"
#include <algorithm>

std::vector<std::shared_ptr<Resource>> ResourceMap::getResources() const
{
    return resources;
}

void ResourceMap::addResource(std::shared_ptr<Resource> resource)
{
    resources.push_back(resource);
}   
    
void ResourceMap::removeResource(std::shared_ptr<Resource> resource)
{
    resources.erase(
        std::remove_if(resources.begin(), resources.end(),
            [&resource](const std::shared_ptr<Resource>& r) {
                return r == resource;
            }),
        resources.end()
    );
}