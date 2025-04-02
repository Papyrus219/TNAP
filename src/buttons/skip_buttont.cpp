#include "skip_buttont.h"

Skip_ButtonT::Skip_ButtonT(std::string path, sf::Vector2f poss, std::pair<int, int> se): ButtonT(path, poss, se)
{}

bool Skip_ButtonT::Clicked(sf::Vector2f x)
{
    if(sprite.getGlobalBounds().contains(x))
    {
        sprite.setTextureRect(Sprites_Variants[0]);
        return true;
    }

    return false;
}

