#include "camerast.h"
#include <iostream>

CamerasT::CamerasT(std::string path, std::string panel_path, std::pair<int,int> se, sf::Vector2f hit_box_size, int camera_acount, int textures_acount, std::vector<int> separator, std::vector<sf::Vector2f> hit_box_possitions): size{se}, camera_panel{panel_path,{10,10},{300,300},hit_box_size,hit_box_possitions} //Standart constructor.
{
    if(!texture.loadFromFile(path))
        std::cerr <<  "Error! Fail to load cameras texture!\n";

    int limit{},y{},act{},act_counter{};
    std::vector<sf::IntRect> tmp{};
    while(limit<textures_acount)
    {
        for(int x=0;x<5;x++)
        {
            tmp.push_back({{size.first*x, size.second*y}, {size.first, size.second}});

            act_counter++;
            if(act_counter == separator[act])
            {
                Variants.push_back(tmp);
                tmp.clear();

                act++;
                act_counter = 0;
            }

            limit++;
        }
        y++;
    }

    for(int i=0;i<camera_acount;i++)
        used_Variants.push_back(Variants[i][0]);

    sprite.setTexture(texture,true);
    sprite.setTextureRect(used_Variants[0]);
}

void CamerasT::Open()
{
    camera_window = new sf::RenderWindow;
    camera_window->create(sf::VideoMode({1000,667}), "Cameras");
}

int CamerasT::Close()
{
    camera_window->close();
    delete camera_window;
    camera_window = nullptr;

    return -3;
}

void CamerasT::Render()
{
    camera_window->draw(sprite);
    camera_window->draw(camera_panel.sprite);
    for(int i=0;i<camera_panel.Hit_box.size();i++)
        camera_window->draw(camera_panel.Hit_box[i]);

    sprite.setTextureRect(used_Variants[act_camera]);
}

void CamerasT::Camera_change()
{
    sf::Vector2f MousePos{sf::Mouse::getPosition(*camera_window)};

    for(int i=0;i<camera_panel.Hit_box.size();i++)
    {
        if(camera_panel.Hit_box[i].getGlobalBounds().contains(MousePos))
        {
            sprite.setTextureRect(used_Variants[i]);
            act_camera = i;
            break;
        }
    }
}

