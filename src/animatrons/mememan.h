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
    void Move() override {};

private:
    MememanButtonT button;
};

#endif // MEMEMAN_H
