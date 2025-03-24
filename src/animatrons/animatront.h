#ifndef ANIMATRONT_H
#define ANIMATRONT_H

#include<iostream>
#include<vector>
#include"../camerast.h"
#include"../officet.h"

class AnimatronT
{
public:
    AnimatronT(int dif, int way_leng, std::vector<std::pair<int,int>> waya);

    bool Move_check(int x) //We check if we can move.
    {return x <= dificulty;}
    virtual void Move(CamerasT &x, OfficeT &y) = 0;

protected:
    int dificulty{};
    int chill{};
    int rage{};
    std::vector<std::pair<int,int>> way;
    const int way_length;
    int actual_possition{};
    bool underdoor{};
};

#endif // ANIMATRONT_H
