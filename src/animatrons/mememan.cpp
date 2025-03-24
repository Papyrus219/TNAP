#include "mememan.h"

Mememan::Mememan(int dif, int way_leng, std::string button_path, std::pair<int, int> button_size): AnimatronT(dif,way_leng,{{0,0}}), button{button_path,{700,400},button_size}
{}

void Mememan::Clicked(sf::Vector2i x)
{
        if(button.Clicked(x))
        {
            actual_possition--;
            button.sprite.setTextureRect(button.Sprites_Variants[0]);
        }
}

void Mememan::Move(CamerasT& x, OfficeT& y)
{
    std::srand(time(NULL));

    if(Move_check(rand()%20))
    {
        std::cerr << "Mememan Move!\n";
        actual_possition++;

        switch(actual_possition)
        {
            case 1:
                    button.sprite.setTextureRect(button.Sprites_Variants[1]);
                    break;
            case 2:
                std::cerr << "Mememan jumpscare!\n";
                actual_possition = 0;
                break;
        }
    }
}
