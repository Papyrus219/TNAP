#ifndef OFFICET_H
#define OFFICET_H

#include<SFML/Graphics.hpp>
#include"header.h"

class OfficeT
{
public:
    OfficeT(std::string door_path, std::string door_button_path, std::string camera_button_path, int Doors_amount, int Cameras_amount , std::pair<int,int> door1_possition, std::pair<int,int> door2_possition, std::pair<int,int> buttons1_possition, std::pair<int,int> buttons2_possition, std::pair<int,int> camera_button_possition); //Constructor.
    OfficeT(OfficeT &); //Copy constructor

    void Show_Tittle_Board(); //To show on begining of each night.
    void Clicked(); //When screen is clicked we will check some options.
    bool Door_status_check(int which) //When animatron ask if door is open.
    {return Door_status[which];}
    void Render(); //To show all office on screen.

private:
    DoorT *Doors; //Pointer to Doors. We will in future allocate here array of Doors.
    ButtonT* *buttons; //Pointer to pointers. We will in future allocate here array of pointers to buttons.
    sf::RectangleShape Scroll_Hitbox[2]; //Hitbox of scroll area.
    bool Door_status[2]{}; //Status of doors.
    int power_usage; //Actual power_usage of office.
    sf::Texture texture; //Texture of office.
    sf::View view; //View. (For scroll effect.
    sf::RenderWindow office_window; //Office window.
    sf::Sprite sprite; //Sprite. This is what we will show on screen.


    ~OfficeT(); //Destructor.
};

#endif // OFFICET_H
