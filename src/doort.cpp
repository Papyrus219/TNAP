#include "doort.h"

DoorT::DoorT(std::string path, std::pair<int, int> poss, int sprite_amount, std::pair<int, int> se): size{se}, possition{poss}
{
    texture.loadFromFile(path);

    for(int i=0;i<sprite_amount;i++)
    {
        Sprites.push_back(sf::Sprite(texture));
        Sprites[i].setTextureRect(sf::IntRect({i*size.first, 0}, {size.first, size.second}));
    }

    for(int i=0;i<3;i++)
        Sprites_Used[i] = &Sprites[i];

    actual_sprite = Sprites_Used[0];
}

DoorT::DoorT(DoorT && other)
{
    actual_sprite = other.actual_sprite;
    size = other.size;
    possition = other.possition;
    texture = other.texture;
    for(auto el : other.Sprites)
        Sprites.push_back(el);
    for(int i=0;i<3;i++)
        Sprites_Used[i] = other.Sprites_Used[i];

    other.actual_sprite = nullptr;
    for(auto el : other.Sprites_Used)
        el = nullptr;
}

