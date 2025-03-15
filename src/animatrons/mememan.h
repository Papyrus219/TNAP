#ifndef MEMEMAN_H
#define MEMEMAN_H

#include"../header.h"
#include"SFML/Graphics.hpp"

class Mememan: public AnimatronT
{
public:
    void Move() override;

private:
    MememanButtonT button;
};

#endif // MEMEMAN_H
