#ifndef CAMERAPANELT_H
#define CAMERAPANELT_H

#include<SFML/Graphics.hpp>
#include"buttont.h"


class CameraPanelT : public ButtonT
{
public:
    CameraPanelT(std::string path, sf::Vector2f possition, std::pair<int,int> size, sf::Vector2f hitbox_size, std::vector<sf::Vector2f> hitboxes); //Normal constructor.

    std::vector<sf::RectangleShape> Hit_box{};

    virtual bool Clicked(sf::Vector2f x) override {return true;};

    ~CameraPanelT(){};

private:


};

#endif // CAMERAPANELT_H
