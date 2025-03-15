#ifndef LIGHT_BUTTONT_H
#define LIGHT_BUTTONT_H

#include<SFML/Graphics.hpp>
#include"buttont.h"

class Light_ButtonT :  public ButtonT
{
public:
    bool Clicked() override; //Overdrive function wich will be called when button was clicked.

    Light_ButtonT(std::string path, std::pair<int,int> size, std::pair<int,int> possition); //Constructor.(Onlhy to call one from ButtonT).
};

#endif // LIGHT_BUTTONT_H
