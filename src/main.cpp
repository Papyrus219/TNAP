#include <SFML/Graphics.hpp>

#include<iostream>
#include "menut.h"
#include"custom_night_menut.h"

#include "officet.h"
#include "camerast.h"

#include "animatrons/animatront.h"
#include "animatrons/papyrus.h"
#include "animatrons/light.h"
#include "animatrons/bot.h"
#include "animatrons/brush.h"
#include "animatrons/mememan.h"

// Papyrus pap{1, 5, {0,1,2,7,9}};
// Light light{1, 7, {0,5,8,6,8,10}};
// Brush brush{20, 6, {0,5,8,10,9}};
// Bot bot{1, 5, {0,1,2,3,4,5}};
// Mememan meme{"../../img/cameras/meme_man_button.png", {750,510}, {300,150}, 1, 2, {0}};

// std::vector<AnimatronT*> ani{&pap, &light, &brush, &bot, &meme};


int main()
{
    MenuT menu{"../../img/menu/menu.png","../../img/menu/menu_button","../../img/menu/star.png","../../audio/background.wav","../../audio/NightStart.wav","../../audio/menu.wav", 4, {{10,180}, {10,310}, {10,440}, {10,570}} ,{375,125}, "../../img/button/skip_button.png", {800,720}, {300,150}};
    Custom_night_menuT cn_menu{&menu,"../../img/menu/custom.png",{193,82},{{10,166},{16,542},{293,168},{320,529},{579,153},{578,535},{793,152},{803,533},{1001,149},{1010,532},{509,783}},{{55,50},{327,54},{611,41},{820,40},{1041,49}},5};
    menu.Load_Text("../../img/fonts/Comic Sans MS.ttf",{344,360},32);

    menu.open();
    while(menu.window->isOpen())
    {
        menu.Render();
        if(const std::optional event = menu.window->pollEvent()) //Hello
        {
            if (event->is<sf::Event::Closed>()) //Standard, we check if window is closed.
            {
                menu.close();
                return 0;
            }
            if(event->is<sf::Event::MouseButtonPressed>())
            {
                menu.Click(cn_menu);
            }
        }
    }

    return 0;
}
