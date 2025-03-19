#ifndef CAMERA_BUTTONT_H
#define CAMERA_BUTTONT_H

#include "../header.h"

/*
 * Actual class of button.
 */

class Camera_ButtonT : public ButtonT
{
public:
    Camera_ButtonT(std::string path, sf::Vector2f possition, std::pair<int,int> size = {28,50}); //Constructor.(Onlhy to call one from ButtonT).

    virtual bool Clicked(sf::Vector2f x) override {return true;}; //Overdrive function wich will be called when button was clicked.

private:
    DoorT *conection{};
};

#endif // CAMERA_BUTTONT_H
