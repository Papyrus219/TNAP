#include <SFML/Graphics.hpp>
#include<iostream>
#include "menut.h"

int main()
{
    MenuT menu{"../../img/menu/menu.png","../../img/menu/menu_button", 4, {{10,180}, {10,310}, {10,440}, {10,570}} ,{375,125}};

    while(menu.window->isOpen())
    {
        menu.Render();
        if(const std::optional event = menu.window->pollEvent()) //Hello
        {
            if (event->is<sf::Event::Closed>()) //Standard, we check if window is closed.
            {
                menu.close();
            }
            if(event->is<sf::Event::MouseButtonPressed>())
            {
                menu.Click();
            }
        }
    }

    return 0;
}
