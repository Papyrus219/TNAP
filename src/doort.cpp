#include "doort.h"
#include<iostream>

DoorT::DoorT(std::string path, sf::Vector2f poss, int sprite_amount, std::pair<int, int> se): size{se}, possition{poss}
{
    if(!texture.loadFromFile(path))
    {
        std::cout << "Error!  Cant load texture of door\n";
    }

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
    std::cout << "Mam cie!\n";
    texture = other.texture;

    sprite.setTexture(texture,true);
    sprite.setPosition(possition);

    for(auto el : other.Sprites_variants)
        Sprites_variants.push_back(el);
    for(int i=0;i<3;i++)
        Used_variants[i] = &Sprites_variants[i];
}

