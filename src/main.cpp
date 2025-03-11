#include <SFML/Graphics.hpp>

int main()
{
    sf::Window window(sf::VideoMode({800,600}),"TNAP");
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) //Hello
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.display();
    }
}
