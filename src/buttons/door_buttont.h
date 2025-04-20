#ifndef DOOR_BUTTONT_H
#define DOOR_BUTTONT_H

#include<SFML/Graphics.hpp>
#include "buttont.h"
#include "../doort.h"

class Door_ButtonT : public ButtonT
{
public:
    Door_ButtonT(std::string path, sf::Vector2f possition, DoorT* con ,std::pair<int,int> se = {28,50}); //Constructor.(Onlhy to call one from ButtonT).
    Door_ButtonT(Door_ButtonT &);
    Door_ButtonT(Door_ButtonT &&);

    virtual bool Clicked(sf::Vector2f x) override; //Overdrive function wich will be called when button was clicked.
    void Power_off();

private:
    DoorT *connection{}; //Pointer to door wich button suposse to close/open.
};

#endif // DOOR_BUTTONT_H
