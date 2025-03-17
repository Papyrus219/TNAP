#include <SFML/Graphics.hpp>
#include"header.h"

int main()
{
    OfficeT office{{1200,1000}, "TNAP", "../../img/office/office.png", "../../img/door/door.png", "../../img/button/button.png", "", 2, 2, {{30,300}, {1020,300}}, {{200,400}, {980,400}}, {0,0}};

    while (office.window->isOpen())
    {
        office.Scroll();

        while (const std::optional event = office.window->pollEvent()) //Hello
        {
            if (event->is<sf::Event::Closed>())
            {
                office.window->close();
            }
        }

        office.Render();
    }
}
