#ifndef MEMEMANBUTTONT_H
#define MEMEMANBUTTONT_H

#include"buttont.h"

class MememanButtonT: public ButtonT
{
public:
    MememanButtonT(std::string path, sf::Vector2f possition, std::pair<int,int> size);

    sf::IntRect Sprites_Variants[2]{}; //Sprites wich we gonna show in screen.

    void Change_sprite(int x)
    {sprite.setTextureRect(Sprites_Variants[x]);}
    bool Clicked(sf::Vector2i x);
};

#endif // MEMEMANBUTTONT_H
