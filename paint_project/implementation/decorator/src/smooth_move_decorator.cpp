#include "smooth_move_decorator.hpp"
#include <thread>
#include <chrono>

SmoothMoveDecorator::SmoothMoveDecorator(std::shared_ptr<Shape> shapePtr): ShapeDecorator(shapePtr){}

void SmoothMoveDecorator::move(Vector2D dest)
{
    if(dest != decoratedShape->coordinates())
    {
        if(dest.x() < decoratedShape->coordinates().x())
        {
            decoratedShape->move({decoratedShape->coordinates().x() - 1, decoratedShape->coordinates().y()});
        }
        else if (dest.x() > decoratedShape->coordinates().x())
        {
            decoratedShape->move({decoratedShape->coordinates().x() + 1, decoratedShape->coordinates().y()});
        }
        if(dest.y() < decoratedShape->coordinates().y())
        {
            decoratedShape->move({decoratedShape->coordinates().x(), decoratedShape->coordinates().y() - 1});
        }
        else if (dest.y() > decoratedShape->coordinates().y())
        {
            decoratedShape->move({decoratedShape->coordinates().x(), decoratedShape->coordinates().y() + 1});
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}