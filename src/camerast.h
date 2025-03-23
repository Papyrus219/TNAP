#ifndef CAMERAST_H
#define CAMERAST_H

#include<SFML/Graphics.hpp>
#include"buttons/camerapanelt.h"

class CamerasT
{
public:
    CamerasT(std::string path, std::string panel_path, std::pair<int,int> se, sf::Vector2f hit_box_size, int camera_acount, int textures_acount, std::vector<int> separation, std::vector<sf::Vector2f> hit_box_possitions); //Standart constructor.

     sf::RenderWindow *camera_window{}; //Pointer to our window. (Its pointer to we can dinamic allocate it.

    void Render(); //We draw actual camera on screen.
    void Open(); //Alocate new window.
    void Close(); //We close window and free memory.
    void Animatron_Update(){}; //Chancge used textures to one with animatron.
    void Camera_change(); //We change camera to one player choose.

    ~CamerasT(){}; //Destructor. (We need to free memory)

private:
    std::pair<int,int> size{};
    sf::Texture texture{};
    sf::Sprite sprite{texture};
    std::vector<sf::IntRect> used_Variants{}; //Pointer to pointer to Sprites. We will in future alocate with it array of pointer to Sprites. (only used ones)
    std::vector<std::vector<sf::IntRect>> Variants{}; //Pointer to actual used sprite.
    CameraPanelT camera_panel;
};

#endif // CAMERAST_H
