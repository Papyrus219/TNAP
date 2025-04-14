#include "doort.h"
#include<iostream>

DoorT::DoorT(std::string path, sf::Vector2f poss, int sprite_amount, std::pair<int, int> se, bool mirror): size{se}, possition{poss} //Constructor of door.
{
    if(!texture.loadFromFile(path)) //We load texture of door.
        std::cout << "Error!  Cant load texture of door\n";

    for(int i=0;i<sprite_amount;i++) //We push to vector, rectangles which are sprites variants.
    {
        Sprites_variants.push_back(sf::IntRect({size.first*i, 0}, {size.first, size.second}));
    }

    for(int i=0;i<3;i++) //3 firsts of sprites variants, become used ones
        Used_variants[i] = Sprites_variants[i];

    sprite.setTexture(texture, true); //We load texture to sprite.
    sprite.setTextureRect(Used_variants[0]); //And set it to be first variants of it.
    if(mirror)
        sprite.setScale({-1.f,1.f});
}

DoorT::DoorT(const DoorT & other) //Copy constructor.
{
    size = other.size;
    possition = other.possition;
    texture = other.texture;

    for(auto el : other.Sprites_variants)
        Sprites_variants.push_back(el);
    for(int i=0;i<3;i++)
        Used_variants[i] = Sprites_variants[i];

    sprite.setTexture(texture,true);
    sprite.setTextureRect(Used_variants[0]);
    sprite.setPosition(possition);
    sprite.setScale(other.sprite.getScale());
}

void DoorT::Close() //Function to call when door is close.
{
    sprite.setTextureRect(Used_variants[1]); //We set to door texture of closed door.
    Texture_status = 1;
    Power_status = true; //And we set door close status to true.
}
void DoorT::Open() //Fuction to call when door is open.
{
    if(!Light_status) //If door is light up:
    {
        sprite.setTextureRect(Used_variants[0]); //If yes, we set door texture to light up one.
        Texture_status = 0;
    }
    else
    {
        sprite.setTextureRect(Used_variants[2]); //If no, we set door texture to light down one.
        Texture_status = 2;
    }
    Power_status = false; //And we set door close status to false.
}
void DoorT::Light_up() //Function to call when door is light up.
{
    if(!Power_status) //If door is open:
    {
        sprite.setTextureRect(Used_variants[2]); //We set door texture to light up one.
        Texture_status = 2;
    }
    Light_status = true; //And we set door light status to true.
}
void DoorT::Light_down() //Function to call when door is light down.
{
    if(!Power_status) //If door is open:
    {
        sprite.setTextureRect(Used_variants[0]); //We set door texture to light down one.
        Texture_status = 0;
    }
    Light_status = false; //And we set door light status to false.
}
void DoorT::Animatron_ahead()
{
    //Emm... to do...
}

