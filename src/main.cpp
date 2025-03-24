#include <SFML/Graphics.hpp>
#include "officet.h"
#include "parameterst.h"
#include "camerast.h"
#include "animatrons/animatront.h"
#include "animatrons/papyrus.h"
#include "animatrons/light.h"
#include "animatrons/bot.h"
#include "animatrons/brush.h"

int main()
{
    OfficeT office{{1200,1000}, "TNAP", "../../img/office/office.png", "../../img/door/door.png", "../../img/button/button.png", "../../img/button/camera.png", 2, 2, {{30,300}, {1020,300}}, {{200,400}, {960,400}}, {100,925}};
    ParametersT par{100,2}; //We define obejct of ParametersT.
    CamerasT cameras{"../../img/cameras/cameras.png", "../../img/cameras/camera_panel.png",{1000,667}, {47,33}, 11, 35, {8,2,2,5,2,2,2,2,2,4,4}, {{99,30},{59,71},{139,70},{28,135},{14,28},
    {233,33},{193,141},{104,170},{250,138},{114,250},{233,251}}};

    Papyrus pap{15,5,{{0,0},{1,1},{2,1},{7,1},{9,1}}};
    Light light{15,6,{{0,0},{5,1},{8,1},{6,1},{8,1},{10,1}}};
    Bot bot{15,5,{{3,0},{3,1},{3,2},{3,3},{3,4}}};
    Brush brush{15,6};

    std::vector<AnimatronT*> anim{};
    anim.push_back(&pap);
    anim.push_back(&bot);
    anim.push_back(&light);
    anim.push_back(&brush);

    while(office.window->isOpen())
    {
        office.Scroll(); //We check if player cursor is in ,,scroll zone".

        if(cameras.camera_window==nullptr)
            office.Camera_Open(cameras); //We check if player open camera.

        if(const std::optional event = office.window->pollEvent()) //Hello
        {
            if (event->is<sf::Event::Closed>()) //Standard, we check if window is closed.
            {
                office.window->close();
            }
            else if(event->is<sf::Event::MouseButtonPressed>()) //We check if window was clicked and then...
            {
                office.Clicked(); //...we start function wich check all elements that can be clicked.
            }
        }

        office.Render(par,cameras); //We render everything on screen.

        if(cameras.camera_window != nullptr)
        {
            cameras.Render();

            if(const std::optional event = cameras.camera_window->pollEvent())
            {
                if(event->is<sf::Event::Closed>())
                {
                    cameras.Close();
                }
                else if(event->is<sf::Event::MouseButtonPressed>())
                {
                    cameras.Camera_change();
                }
            }
        }


        if(par.Tic()) //And check if tic happen.
        {
            for(auto el : anim)
                el->Move(cameras,office);
        }
    }
}
