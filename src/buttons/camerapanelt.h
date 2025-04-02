#ifndef CAMERAPANELT_H
#define CAMERAPANELT_H

#include<SFML/Graphics.hpp>
#include"buttont.h"


class CameraPanelT : public ButtonT
{
public:
    CameraPanelT(std::string path, sf::Vector2f possition, std::pair<int,int> size, sf::Vector2f hitbox_size, std::vector<sf::Vector2f> hitboxes); //Normal constructor.

    std::vector<sf::RectangleShape> Hit_box{}; //Vector of hitboxes (To know where thouse little buttons on panel are).

    virtual bool Clicked(sf::Vector2f x) override {return true;}; //We need to override function to dont make class abstract.

};

#endif // CAMERAPANELT_H
