#ifndef CAMERAPANELT_H
#define CAMERAPANELT_H

#include<SFML/Graphics.hpp>
#include"buttont.h"


class CameraPanelT : public ButtonT
{
public:
    CameraPanelT(std::string path, sf::Vector2f possition, std::pair<int,int> size, int hit_box_amount); //Normal constructor.

    virtual bool Clicked(sf::Vector2f x) override {return true;};

    ~CameraPanelT(){};

private:
    sf::RectangleShape *Hit_boxy{};

};

#endif // CAMERAPANELT_H
