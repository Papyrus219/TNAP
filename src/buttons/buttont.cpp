#include "buttont.h"
#include<iostream>

ButtonT::ButtonT(std::string path, sf::Vector2f pos, std::pair<int,int> se = {28,50}): possition{pos}, size{se}
{
    if(!texture.loadFromFile(path))
        std::cout << "Error! Fail to load texture of button.\n";

    for(int i=0;i<2;i++)
    {
        Sprites_Variants[i] = sf::IntRect({i*size.first, 0}, {size.first, size.second});
    }

    sprite.setTexture(texture,true);
    sprite.setTextureRect(Sprites_Variants[0]);
    sprite.setPosition(possition);
}

ButtonT::ButtonT(ButtonT & other)
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

ButtonT::ButtonT(ButtonT && other)
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
