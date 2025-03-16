#ifndef CAMERAST_H
#define CAMERAST_H

#include<SFML/Graphics.hpp>
#include"buttons/camerapanelt.h"

class CamerasT
{
public:
    CamerasT(std::string path, int camera_acount, int textures_acount); //Standart constructor.
    CamerasT(const CamerasT& other); //Copy constructor.

    void Render(){}; //We draw actual camera on screen.
    void Open(){}; //Alocate new window.
    void close(){}; //We close window and free memory.
    void Animatron_Update(){}; //Chancge used textures to one with animatron.
    void Camera_change(int act_cam) //We change camera to one player choose.
    {*actual_sprite = *used_Sprites[act_cam];}

private:
    CameraPanelT camera_panel {"",{10,10},{10,10},1};
    sf::RenderWindow *camera_window; //Pointer to our window. (Its pointer to we can dinamic allocate it.
    sf::Sprite *Sprites; //Pointer to Sprites. We will in future alocate with it array of Sprites. (total)
    sf::Sprite* *used_Sprites; //Pointer to pointer to Sprites. We will in future alocate with it array of pointer to Sprites. (only used ones)
    sf::Sprite* actual_sprite; //Pointer to actual used sprite.

     ~CamerasT(){}; //Destructor. (We need to free memory)
};

#endif // CAMERAST_H
