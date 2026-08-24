#include "greedy_strategy.hpp"

std::shared_ptr<Resource> GreedyStrategy::targetResource(
    const std::vector<std::shared_ptr<Resource>>& resources,
    const Vector2D& coords) const
{
    std::shared_ptr<Resource> result;
    std::size_t bestSize = 0;

    for (const auto& item : resources)
    {
        if (!item) continue;
        if (item->dimensions() >= bestSize)
        {
            result = item;
            bestSize = item->dimensions();
        }
    }
    return result;
}