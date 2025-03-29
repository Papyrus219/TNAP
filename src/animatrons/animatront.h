#ifndef ANIMATRONT_H
#define ANIMATRONT_H

#include<iostream>
#include<vector>
#include"../camerast.h"
#include"../officet.h"

struct error
{};

class AnimatronT
{
public:
    AnimatronT(int dif, int way_leng, std::vector<int> waya);

    static std::vector<int> Possitions;
    bool Move_check(int x) //We check if we can move.
    {return x <= dificulty;}
    virtual std::vector<int> Move(OfficeT &x) = 0;

protected:
    int dificulty{};
    int chill{};
    int rage{};
    std::vector<int> way;
    const int way_length;
    int actual_possition{};
    bool underdoor{};

    friend class ParametersT;
};

#endif // ANIMATRONT_H
