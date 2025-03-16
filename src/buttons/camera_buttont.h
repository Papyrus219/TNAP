#ifndef CAMERA_BUTTONT_H
#define CAMERA_BUTTONT_H

#include "buttont.h"

/*
 * Actual class of button.
 */

class Camera_ButtonT : public ButtonT
{
public:
    virtual bool Clicked() override {return true;}; //Overdrive function wich will be called when button was clicked.

    Camera_ButtonT(std::string path, std::pair<int,int> size, std::pair<int,int> possition); //Constructor.(Onlhy to call one from ButtonT).
};

#endif // CAMERA_BUTTONT_H
