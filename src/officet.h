#ifndef OFFICET_H
#define OFFICET_H

#include<SFML/Graphics.hpp>
#include"doort.h"
#include"buttons/light_buttont.h"
#include"buttons/door_buttont.h"

class OfficeT
{
public:
    OfficeT(sf::Vector2u window_size, std::string window_name,std::string office_path,std::string door_path, std::string button_path, std::string camera_button_path, int doors_amount, int buttons_amount , std::vector<sf::Vector2f> Door_possition, std::vector<sf::Vector2f> Buttons_possition, sf::Vector2f camera_button_possition); //Constructor.
    OfficeT(OfficeT &); //Copy constructor

    sf::RenderWindow* window; //Office window.

    void Show_Tittle_Board(); //To show on begining of each night.
    void Clicked(); //When screen is clicked we will check some options.
    void Scroll();
    bool Door_status_check(int which) //When animatron ask if door is open.
    {return Door_status[which];}
    void Render(); //To show all office on screen.

    ~OfficeT(); //Destructor.

private:
    std::vector<DoorT> Doors{}; //Vector of doors.
    std::vector<Door_ButtonT> Door_Buttons{}; //Vector of buttons.
    std::vector<Light_ButtonT> Light_Buttons{}; //Vector of buttons.
    sf::RectangleShape Scroll_Hitbox[2]; //Hitbox of scroll area.
    bool Door_status[2]{}; //Status of doors.
    int power_usage; //Actual power_usage of office.
    sf::Texture texture; //Texture of office.
    sf::View view; //View. (For scroll effect.
    sf::Sprite sprite{texture}; //Sprite. This is what we will show on screen.
};

#endif // OFFICET_H
