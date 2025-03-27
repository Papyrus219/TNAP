#ifndef MEMEMAN_H
#define MEMEMAN_H

#include"SFML/Graphics.hpp"
#include "animatront.h"
#include "../buttons/mememanbuttont.h"

/*
 * Warning! Define only one object of this class!
 * Another can fill all computer memory and crush system!
 */

class Mememan: public AnimatronT
{
public:
    Mememan(std::string path, sf::Vector2f pos, std::pair<int,int> se, int dif, int path_len, std::vector<int> waya);
    std::vector<int> Move(OfficeT &x) override;

private:
    MememanButtonT button;
    friend class CamerasT;
};

#endif // MEMEMAN_H
