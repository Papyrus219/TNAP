#ifndef SKIP_BUTTONT_H
#define SKIP_BUTTONT_H

#include "buttont.h"

class Skip_ButtonT :  public ButtonT
{
public:
    bool Clicked(sf::Vector2f x) override;

    Skip_ButtonT(std::string path, sf::Vector2f poss, std::pair<int,int> se);
    Skip_ButtonT() = default;

    void Set_sprite_variant(int x)
    {
        if(x<2) sprite.setTextureRect(Sprites_Variants[x]);
        actual_variant = 1;
    }

    ~Skip_ButtonT() = default;
};

#endif // SKIP_BUTTONT_H
