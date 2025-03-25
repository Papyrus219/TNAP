#include "light_buttont.h"

Light_ButtonT::Light_ButtonT(std::string path, sf::Vector2f possition, DoorT* con, std::pair<int,int> se): ButtonT(path,possition,se) , conection{con} //Standart constructor.
{}

Light_ButtonT::Light_ButtonT(Light_ButtonT& other): ButtonT(other) //Copy constructor.
{
    conection = other.conection;
}

Light_ButtonT::Light_ButtonT(Light_ButtonT&& other): ButtonT(other) //Move constructor. (Do same what copy cojnstructor, becouse i am noob.)
{
    conection = other.conection;
}

bool Light_ButtonT::Clicked(sf::Vector2f x) //Function that check if button is clicked and if yes: light up door.
{
    if(sprite.getGlobalBounds().contains(x)) //If button was Clicked:
    {
        if(status) //And lighted up:
        {
            sprite.setTextureRect(Sprites_Variants[0]); //We set button texture to off.
            conection->Light_down(); //We call conected door light down function.
            status = false; //We set light button status to false.
        }
        else //And lighted down:
        {
            sprite.setTextureRect(Sprites_Variants[1]); //We set button texture to om.
            conection->Light_up(); //We call conected door light up function.
            status = true; //We set light button to true.
        }

        return true;
    }
    else
        return false;
}
