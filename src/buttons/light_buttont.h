#ifndef LIGHT_BUTTONT_H
#define LIGHT_BUTTONT_H

#include "buttont.h"
#include "../doort.h"

class Light_ButtonT :  public ButtonT
{
public:
    Light_ButtonT(std::string path, sf::Vector2f possition, DoorT* con, std::pair<int,int> se = {28,50}); //Constructor.(Onlhy to call one from ButtonT).
    Light_ButtonT(Light_ButtonT&);
    Light_ButtonT(Light_ButtonT&&);

    bool Clicked(sf::Vector2f x) override; //Overdrive function wich will be called when button was clicked.

private:
    DoorT *conection{}; //Pointer to door wich button suposse to light up.
};

#endif // LIGHT_BUTTONT_H
