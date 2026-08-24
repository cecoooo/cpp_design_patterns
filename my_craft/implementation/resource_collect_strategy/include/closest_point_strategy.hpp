#pragma once
#include "strategy.hpp"

class ClosestPointStrategy : public Strategy
{
public:
    std::shared_ptr<Resource> targetResource(
        const std::vector<std::shared_ptr<Resource>>& resources,
        const Vector2D& coords) const override;
}