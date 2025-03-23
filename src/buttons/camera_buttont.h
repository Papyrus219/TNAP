#ifndef CAMERA_BUTTONT_H
#define CAMERA_BUTTONT_H

#include "SFML/Graphics.hpp"
#include "buttont.h"
#include "../doort.h"

/*
 * Actual class of button.
 */

class Camera_ButtonT : public ButtonT
{
public:
    Camera_ButtonT(std::string path, sf::Vector2f possition, std::pair<int,int> size = {1000,75}); //Constructor.(Onlhy to call one from ButtonT).

    virtual bool Clicked(sf::Vector2f x) override{return false;}; //Overdrive function wich will be called when button was clicked.

private:
    DoorT *conection{};
};

#endif // CAMERA_BUTTONT_H
