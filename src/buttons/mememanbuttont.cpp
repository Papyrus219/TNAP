#include "mememanbuttont.h"
#include<iostream>

MememanButtonT::MememanButtonT(std::string path, sf::Vector2f possition ,std::pair<int,int> size): ButtonT(path,possition,size)
{
    if(!texture.loadFromFile(path))
        std::cerr << "Error! Fail to load meme_man_button_texture!\n";

    for(int i=0;i<2;i++)
    {
        Sprites_Variants[i] = sf::IntRect{{i*size.first, 0}, {size.first, size.second}};
    }
    sprite.setTexture(texture,true);
    sprite.setTextureRect(Sprites_Variants[0]);
    sprite.setPosition(possition);
}

bool MememanButtonT::Clicked(sf::Vector2i x)
{
    if(sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(x)))
        return true;
    else
        return false;
}
