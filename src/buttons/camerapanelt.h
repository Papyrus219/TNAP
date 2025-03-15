#ifndef CAMERAPANELT_H
#define CAMERAPANELT_H

#include<SFML/Graphics.hpp>
#include"buttont.h"


class CameraPanelT : public ButtonT
{
public:
    CameraPanelT(std::string path, std::pair<int,int> size, std::pair<int,int> possition, int hit_box_amount); //Normal constructor.

    bool Clicked() override;

private:
    sf::RectangleShape *Hit_boxy{};

    ~CameraPanelT();
};

#endif // CAMERAPANELT_H
