#include <SFML/Graphics.hpp>
<<<<<<< HEAD
#include<iostream>
#include "menut.h"
=======
#include "officet.h"
#include "camerast.h"
#include "parameterst.h"
#include "animatrons/animatront.h"
#include "animatrons/papyrus.h"
#include "animatrons/light.h"
#include "animatrons/bot.h"
#include "animatrons/brush.h"
#include "animatrons/mememan.h"

Papyrus pap{1, 5, {0,1,2,7,9}};
Light light{1, 7, {0,5,8,6,8,10}};
Brush brush{20, 6, {0,5,8,10,9}};
Bot bot{1, 5, {0,1,2,3,4,5}};
Mememan meme{"../../img/cameras/meme_man_button.png", {750,510}, {300,150}, 1, 2, {0}};

std::vector<AnimatronT*> ani{&pap, &light, &brush, &bot, &meme};
>>>>>>> 8fca2d67e76a609a4a68357eef7f2ec93000d72c

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
