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
    OfficeT office{{1200,1000}, "TNAP", "../../img/office/office.png", "../../img/door/door.png", "../../img/button/button.png", "../../img/button/camera.png", 2, 2, {{30,300}, {1020,300}}, {{200,400}, {960,400}}, {100,925}}; //We define object of OfficeT.
    ParametersT par{100,1}; //We define obejct of ParametersT.
    CamerasT cameras{"../../img/cameras/cameras.png", "../../img/cameras/camera_panel.png",{1000,667}, {47,33}, 11, 35, {8,2,2,5,2,2,2,2,2,4,4}, {{99,30},{59,71},{139,70},{28,135},{14,28},
    {233,33},{193,141},{104,170},{250,138},{114,250},{233,251}}}; //We define object of CamerasT.

    while(office.window->isOpen())
    {
        office.Scroll(); //We check if player cursor is in ,,scroll zone".

        if(cameras.camera_window==nullptr)
            if(office.Camera_Open(cameras)) //We check if player open camera.
                office.Update_Energy_Usage(3);

        if(const std::optional event = office.window->pollEvent()) //Hello
        {
            if (event->is<sf::Event::Closed>()) //Standard, we check if window is closed.
            {
                office.window->close(); //We close window.
                office.Update_Energy_Usage(-3); //We update energy ussage.
            }
            else if(event->is<sf::Event::MouseButtonPressed>()) //We check if window was clicked and then...
            {
                office.Clicked(); //...we start function wich check all elements that can be clicked.
            }
        }

        office.Render(par,cameras); //We render everything in office.

        if(cameras.camera_window != nullptr) //If camera window exist.
        {
            cameras.Render(); //We render everything in cameras.

            if(const std::optional event = cameras.camera_window->pollEvent()) //If any event in camera window detected:
            {
                if(event->is<sf::Event::Closed>()) //We check if player close window.
                {
                    cameras.Close(); //If yes, we need to run function that free memory, and clean up.
                    office.Update_Energy_Usage(-3);
                }
                else if(event->is<sf::Event::MouseButtonPressed>()) //If button presed:
                {
                    cameras.Camera_change(); //If yes, we run function which check if player.
                }
            }
        }


        if(par.Tic()) //And check if tic happen.
        {
        }
    }
}
