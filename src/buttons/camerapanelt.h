#ifndef CAMERAPANELT_H
#define CAMERAPANELT_H

#include<SFML/Graphics.hpp>
#include"buttont.h"


class CameraPanelT : public ButtonT
{
public:
    CameraPanelT(std::string path, std::pair<int,int> size, std::pair<int,int> possition, int hit_box_amount); //Normal constructor.

    virtual bool Clicked() override {return true;};

    ~CameraPanelT(){};

private:
    sf::RectangleShape *Hit_boxy{};

};

#endif // CAMERAPANELT_H
