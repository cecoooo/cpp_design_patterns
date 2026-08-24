#include "closest_point_strategy.hpp"
#include <limits>

std::shared_ptr<Resource> ClosestPointStrategy::targetResource(
    const std::vector<std::shared_ptr<Resource>>& resources,
    const Vector2D& coords) const
{
    std::shared_ptr<Resource> result;
    float minDist = std::numeric_limits<float>::max();

    for (const auto& item : resources)
    {
        if (!item) continue;
        float dist = coords.distance(item->position());
        if (dist < minDist)
        {
            result = item;
            minDist = dist;
        }
    }
    return result;
}