#include <SFML/Graphics.hpp>
#include <memory>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Hello World");
    sf::CircleShape shape(200);
    std::shared_ptr<sf::Shape> sh = std::make_shared<sf::CircleShape>(sf::CircleShape(100, 3));
    sh->setFillColor(sf::Color::Red);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type ==sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(shape);
        window.draw(*sh);
        window.display();
    }
    return 0;
}
