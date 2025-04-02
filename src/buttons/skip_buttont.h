#ifndef SKIP_BUTTONT_H
#define SKIP_BUTTONT_H

#include "buttont.h"

class Skip_ButtonT :  public ButtonT
{
public:
    bool Clicked(sf::Vector2f x) override;

    Skip_ButtonT(std::string path, sf::Vector2f poss, std::pair<int,int> se);

    void Set_sprite_variant(int x)
    {sprite.setTextureRect(Sprites_Variants[x]);}

    ~Skip_ButtonT() override;
};

#endif // SKIP_BUTTONT_H
