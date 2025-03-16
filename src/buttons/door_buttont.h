#ifndef DOOR_BUTTONT_H
#define DOOR_BUTTONT_H

#include "buttont.h"

class Door_ButtonT : public ButtonT
{
public:
    virtual bool Clicked() override {return false;}; //Overdrive function wich will be called when button was clicked.

    Door_ButtonT(std::string path, std::pair<int,int> possition, std::pair<int,int> se = {50,50}); //Constructor.(Onlhy to call one from ButtonT).
};

#endif // DOOR_BUTTONT_H
