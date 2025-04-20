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

bool Door_ButtonT::Clicked(sf::Vector2f x) //Function that check if button is clicked.
{
    if(sprite.getGlobalBounds().contains(x)) //If yes:
    {
        if(status) //Then we check if door closed:
        {
            sprite.setTextureRect(Sprites_Variants[0]); //If yes we turn button off.
            connection->Open(); //And call door open function.
            status = false; //And set door button to off.
        }
        else
        {
            sprite.setTextureRect(Sprites_Variants[1]); //If no we turn button on.
            connection->Close(); //And call door open function.
            status = true; //And set door button to on.
        }

        return true;
    }
    else
        return false;
}

void Door_ButtonT::Power_off()
{
    sprite.setTextureRect(Sprites_Variants[0]);
    connection->Open();
    status = false;
}
