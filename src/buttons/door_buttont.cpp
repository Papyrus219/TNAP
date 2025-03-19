#include "door_buttont.h"

Door_ButtonT::Door_ButtonT(std::string path, sf::Vector2f possition, DoorT* con, std::pair<int,int> se): ButtonT(path,possition,se), connection{con}
{}

Door_ButtonT::Door_ButtonT(Door_ButtonT& other): ButtonT(other)
{
    connection = other.connection;
}

Door_ButtonT::Door_ButtonT(Door_ButtonT&& other): ButtonT(other)
{
    connection = other.connection;
}

bool Door_ButtonT::Clicked(sf::Vector2f x)
{
    if(sprite.getGlobalBounds().contains(x))
    {
        if(status)
        {
            sprite.setTextureRect(Sprites_Variants[0]);
            connection->Open();
            status = false;
        }
        else
        {
            sprite.setTextureRect(Sprites_Variants[1]);
            connection->Close();
            status = true;
        }

        return true;
    }
    else
        return false;
}
