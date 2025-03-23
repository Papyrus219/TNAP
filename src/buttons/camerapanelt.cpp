#include "camerapanelt.h"
#include<iostream>

CameraPanelT::CameraPanelT(std::string path, sf::Vector2f possition, std::pair<int,int> size, sf::Vector2f hitbox_size, std::vector<sf::Vector2f> hitboxes): ButtonT(path,possition,size)
{
    if(!texture.loadFromFile(path))
    {
        std::cerr << "Error! Fail to load camera panel texture.\n";
    }

    sprite.setTexture(texture, true);
    sprite.setPosition(possition);

    for(int i=0;i<hitboxes.size();i++)
    {
        sf::RectangleShape x{{hitbox_size.x, hitbox_size.y}};
        x.setPosition({hitboxes[i].x, hitboxes[i].y});
        x.setFillColor(sf::Color::Transparent);
        Hit_box.push_back(x);
    }
}
