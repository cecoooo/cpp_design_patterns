#pragma once
#include "resource.hpp"
#include "vector_2d.hpp"
#include <memory>
#include <vector>

class Strategy
{
public:
    virtual ~Strategy() = default;

    virtual std::shared_ptr<Resource> targetResource(
        const std::vector<std::shared_ptr<Resource>>& resources,
        const Vector2D& coords) const = 0;
};