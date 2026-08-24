#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <cmath>
#include "vector_2d.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "canvas.hpp"
#include "smooth_move_decorator.hpp"
#include "sfml_window_adapter.hpp"
#include "color.hpp"
#include "rotate_command.hpp"
#include "undo_redo_commander.hpp"
#include "rotate_visitor.hpp"
#include "color_visitor.hpp"
#include "context.hpp"

int main()
{
    std::shared_ptr<Window> window = std::make_shared<SfmlWindowAdapter>(1920, 1056, "OOPaint");

    std::shared_ptr<Circle> circle = std::make_shared<Circle>(Vector2D(30, 40), RED, 10);
    std::shared_ptr<Rectangle> rect = std::make_shared<Rectangle>(Vector2D(30, 50), BLUE, 10, 20);
    Canvas canvas;
    canvas.addShape(circle);
    canvas.addShape(rect);
    SmoothMoveDecorator smoothMoveDecorator(std::make_shared<Canvas>(canvas));

    RotateCommand rotComm(std::make_shared<Canvas>(canvas), 45);
    UndoRedoCommander undoRedoCommander;
    undoRedoCommander.addCommand(std::make_unique<RotateCommand>(rotComm));

    std::shared_ptr<ShapeVisitor> scaleVisitor = std::make_shared<ColorVisitor>();
    std::shared_ptr<ShapeVisitor> rotateVisitor = std::make_shared<RotateVisitor>();
    Context context;

    Rectangle rectangle(Vector2D(50, 100), CYAN, 20, 30);

    int i = 0;

    window->startWindow();
    std::thread changeShapeCoords;
    while (window->isOpen())
    {
        if(window->checkForCloseEvent())
        {
            window->stopWindow();
        }
        std::optional<Vector2D> cursorCoords = window->catchLeftButtonClick();
        if (cursorCoords.has_value() && !changeShapeCoords.joinable()) 
        {
            if((std::abs(cursorCoords.value().x() - rect->coordinates().x()) <= 10) 
               && (std::abs(cursorCoords.value().y() - rect->coordinates().y()) <= 10))
            {
                changeShapeCoords = std::thread(&Context::execute, &context, rect, window);
            }
            else if((std::abs(cursorCoords.value().x() - circle->coordinates().x()) <= 10) 
               && (std::abs(cursorCoords.value().y() - circle->coordinates().y()) <= 10))
            {
                changeShapeCoords = std::thread(&Context::execute, &context, circle, window);
            }
            else if((std::abs(cursorCoords.value().x() - rectangle.coordinates().x()) <= 10) 
               && (std::abs(cursorCoords.value().y() - rectangle.coordinates().y()) <= 10))
            {
                changeShapeCoords = std::thread(&Context::execute, &context, std::make_shared<Rectangle>(rectangle), window);
                std::cout << "inside if rectangle" << std::endl;
            }
            std::cout << "inside if left click" << std::endl;
        }

        window->clear();
        canvas.draw(window);
        rectangle.draw(window);
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        //std::this_thread::sleep_for(std::chrono::seconds(5));
        //canvas.scale(100);
        // smoothMoveDecorator.move({300, 200});
        // rectangle.accept(scaleVisitor);
        // rectangle.accept(rotateVisitor);
        // //smoothMoveDecorator.rotate(30);
        // if(i > 50)
        // {
        //     undoRedoCommander.undo();
        //     i=0;
        // }
        // else 
        // {
        //     undoRedoCommander.redo();
        // }
        // i++;
    }
    if (changeShapeCoords.joinable()) {
        changeShapeCoords.join();
    }
    return 0;
}