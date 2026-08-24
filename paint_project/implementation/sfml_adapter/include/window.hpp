#pragma once
#include <vector>
#include <string>
#include <optional>
#include "vector_2d.hpp"
#include "color.hpp"
#include "shape_type.hpp"

class Window
{
protected:
    unsigned int length;
    unsigned int width;
    std::string windowName;
public:
    Window(unsigned int len, unsigned int wid, std::string name);
    virtual ~Window()=0;
    virtual void startWindow()=0;
    virtual void stopWindow()=0;
    virtual bool isOpen()=0;
    virtual bool checkForCloseEvent()=0;
    virtual void clear()=0;
    virtual void draw(Vector2D position, const std::vector<float>& sizes, Color col, ShapeType sht, float rotation)=0;
    virtual void refresh()=0;
    virtual std::optional<Vector2D> catchLeftButtonClick()=0;
    virtual std::optional<Vector2D> catchRightButtonClick()=0;
    virtual std::optional<Vector2D> catchMiddleButtonClick()=0;
    virtual Vector2D getMousePosition()=0;
};