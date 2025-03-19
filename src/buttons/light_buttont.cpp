#include "light_buttont.h"

Light_ButtonT::Light_ButtonT(std::string path, sf::Vector2f possition, DoorT* con, std::pair<int,int> se): ButtonT(path,possition,se) , conection{con}
{}

Light_ButtonT::Light_ButtonT(Light_ButtonT& other): ButtonT(other)
{
    conection = other.conection;
}

Light_ButtonT::Light_ButtonT(Light_ButtonT&& other): ButtonT(other)
{
    conection = other.conection;
}

bool Light_ButtonT::Clicked(sf::Vector2f x)
{
    if(sprite.getGlobalBounds().contains(x))
    {
        if(status)
        {
            sprite.setTextureRect(Sprites_Variants[0]);
            conection->Light_down();
            status = false;
        }
        else
        {
            sprite.setTextureRect(Sprites_Variants[1]);
            conection->Light_up();
            status = true;
        }

        return true;
    }
    else
        return false;
}
