#include "buttont.h"

ButtonT::ButtonT(std::string path, std::pair<int,int> pos, std::pair<int,int> se): possition{pos}, size{se}
{
    texture.loadFromFile(path);

    for(int i=0;i<2;i++)
    {
        Sprites[i].setTexture(texture);
        Sprites[i].setTextureRect(sf::IntRect({i*size.first, 0}, {size.first, size.second}));
    }

    actual_sprite = &Sprites[0];
}

ButtonT::ButtonT(ButtonT && other)
{
    actual_sprite = other.actual_sprite;
    possition = other.possition;
    size = other.size;
    texture = other.texture;
    for(int i=0;i<2;i++)
        Sprites[i] = other.Sprites[i];

    other.actual_sprite = nullptr;
}

