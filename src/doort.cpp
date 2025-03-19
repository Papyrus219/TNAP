#include "doort.h"
#include<iostream>

DoorT::DoorT(std::string path, sf::Vector2f poss, int sprite_amount, std::pair<int, int> se): size{se}, possition{poss}
{
    if(!texture.loadFromFile(path))
        std::cout << "Error!  Cant load texture of door\n";

    for(int i=0;i<sprite_amount;i++)
    {
        Sprites_variants.push_back(sf::IntRect({size.first*i, 0}, {size.first, size.second}));
    }

    for(int i=0;i<3;i++)
        Used_variants[i] = &Sprites_variants[i];

    sprite.setTexture(texture, true);
    sprite.setTextureRect(*Used_variants[0]);
}

DoorT::DoorT(const DoorT & other)
{
    size = other.size;
    possition = other.possition;
    texture = other.texture;

    for(auto el : other.Sprites_variants)
        Sprites_variants.push_back(el);
    for(int i=0;i<3;i++)
        Used_variants[i] = &Sprites_variants[i];

    sprite.setTexture(texture,true);
    sprite.setTextureRect(*Used_variants[0]);
    sprite.setPosition(possition);
}

void DoorT::Close() //Function to call when door is close.
{
    sprite.setTextureRect(*Used_variants[1]);
    Power_status = true;
}
void DoorT::Open() //Fuction to call when door is open.
{
    if(!Light_status)
        sprite.setTextureRect(*Used_variants[0]);
    else
        sprite.setTextureRect(*Used_variants[2]);
    Power_status = false;
}
void DoorT::Light_up() //Function to call when door is light up.
{
    if(!Power_status)
        sprite.setTextureRect(*Used_variants[2]);
    Light_status = true;
}
void DoorT::Light_down() //Function to call when door is light down.
{
    if(!Power_status)
        sprite.setTextureRect(*Used_variants[0]);
    Light_status = false;
}
void DoorT::Animatron_ahead()
{

}

