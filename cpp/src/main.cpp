#include "draw.hpp"

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Joe Chess");

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                // Handle mouse click
            }
        }
        window.clear();
        drawBoard(window);
        //draw pieces
        window.display();
    }
    
    return 0;
}