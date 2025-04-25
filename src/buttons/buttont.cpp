#include "buttont.h"
#include<iostream>
#include<string>

ButtonT::ButtonT(std::string path, sf::Vector2f pos, std::pair<int,int> se = {28,50}): possition{pos}, size{se} //Standart constructor.
{
    if(!texture.loadFromFile("../../img/mememan.png"))
    {
        int GDZIEMEMEMAN{-69};
        throw GDZIEMEMEMAN;
    }

    if(!texture.loadFromFile(path)) //We load texture of button.
        std::cout << "Error! Fail to load texture of button.\n";

    for(int i=0;i<2;i++) //Each button have two sprites variant (on and off), we crop each of them.
    {
        Sprites_Variants[i] = sf::IntRect({i*size.first, 0}, {size.first, size.second});
    }

    sprite.setTexture(texture,true); //We set texture to sprite.
    sprite.setTextureRect(Sprites_Variants[0]); //We set to first variant (off).
    sprite.setPosition(possition); //We set position of button.
}

ButtonT::ButtonT(ButtonT & other) //Copy constructor.
{
    possition = other.possition;
    size = other.size;
    texture = other.texture;
    for(int i=0;i<2;i++)
        Sprites_Variants[i] = other.Sprites_Variants[i];

    sprite.setTexture(texture,true);
    sprite.setTextureRect(Sprites_Variants[0]);
    sprite.setPosition(possition);
}

ButtonT::ButtonT(ButtonT && other) //Move constructor. (Same as copy constructor, becouse i am noob).
{
    possition = other.possition;
    size = other.size;
    texture = other.texture;
    for(int i=0;i<2;i++)
        Sprites_Variants[i] = other.Sprites_Variants[i];

    sprite.setTexture(texture,true);
    sprite.setTextureRect(Sprites_Variants[0]);
    sprite.setPosition(possition);
}
