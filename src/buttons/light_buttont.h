#ifndef LIGHT_BUTTONT_H
#define LIGHT_BUTTONT_H

#include "buttont.h"
#include "../doort.h"

class Light_ButtonT :  public ButtonT
{
public:
    Light_ButtonT(std::string path, sf::Vector2f possition, DoorT* con, std::pair<int,int> se = {28,50}); //Constructor.(Onlhy to call one from ButtonT).
    Light_ButtonT(Light_ButtonT&); //Copy contructor.
    Light_ButtonT(Light_ButtonT&&); //Move constructor.

    bool Clicked(sf::Vector2f x) override; //Overdrive function wich will be called when button was clicked.
    void Power_off();

private:
    DoorT *conection{}; //Pointer to door wich button suposse to light up/down.
};

#endif // LIGHT_BUTTONT_H
