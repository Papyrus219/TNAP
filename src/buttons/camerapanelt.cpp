#include "camerapanelt.h"
#include<iostream>

CameraPanelT::CameraPanelT(std::string path, sf::Vector2f possition, std::pair<int,int> size, sf::Vector2f hitbox_size, std::vector<sf::Vector2f> hitboxes): ButtonT{path, possition, size} //Standart constructor.
{
    if(!texture.loadFromFile(path)) //We load texture of panel.
    {
        std::cerr << "Error! Fail to load camera panel texture.\n";
    }

    sprite.setTexture(texture, true); //We set sprite texture.
    sprite.setPosition(possition); //We set sprite possition.

    for(int i=0;i<hitboxes.size();i++) //For each called hitbox:
    {
        sf::RectangleShape x{{hitbox_size.x, hitbox_size.y}}; //We set it size.
        x.setPosition({hitboxes[i].x, hitboxes[i].y}); //We set it possition.
        x.setFillColor(sf::Color::Transparent); //We set it color.
        Hit_box.push_back(x); //We push it to vector.
    }
}
