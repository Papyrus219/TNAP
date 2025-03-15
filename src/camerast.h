#ifndef CAMERAST_H
#define CAMERAST_H

#include<SFML/Graphics.hpp>
#include"buttons/camerapanelt.h"

class CamerasT
{
public:
    CamerasT(std::string path, int camera_acount, int textures_acount); //Standart constructor.
    CamerasT(const CamerasT& other); //Copy constructor.

    void Render(); //We draw actual camera on screen.
    void Open(); //Alocate new window.
    void close(); //We close window and free memory.
    void Animatron_Update(); //Chancge used textures to one with animatron.
    void Camera_change(int act_cam) //We change camera to one player choose.
    {sprite.setTexture(*used_Textures[act_cam]);}

private:
    CameraPanelT camera_panel;
    sf::Texture *Textures; //Pointer to textures. We will in future alocate with it array of textures. (total)
    sf::Texture* *used_Textures; //Pointer to pointer to textures. We will in future alocate with it array of pointer to textured. (only used ones)
    sf::RenderWindow *camera_window; //Pointer to our window. (Its pointer to we can dinamic allocate it.
    sf::Sprite sprite; //Sprite of actual window that we will draw.

     ~CamerasT(); //Destructor. (We need to free memory)
};

#endif // CAMERAST_H
