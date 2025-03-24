#ifndef MEMEMAN_H
#define MEMEMAN_H

#include"../header.h"
#include"SFML/Graphics.hpp"

/*
 * Warning! Define only one object of this class!
 * Another can fill all computer memory and crush system!
 */

class Mememan: public AnimatronT
{
public:
    Mememan(int dif, int way_leng, std::string button_path, std::pair<int,int> button_size);

    void Move(CamerasT &x, OfficeT &y) override;
    void Clicked(sf::Vector2i x);
    void Change_sprite(int x)
    {button.Change_sprite(x);}

    MememanButtonT button;

    friend class CamerasT;
};

#endif // MEMEMAN_H
