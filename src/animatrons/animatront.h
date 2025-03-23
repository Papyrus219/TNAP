#ifndef ANIMATRONT_H
#define ANIMATRONT_H

#include<iostream>
#include<vector>

class AnimatronT
{
public:
    AnimatronT(int dif,std::vector<std::pair<int,int>> way);

    bool Move_check(int x) //We check if we can move.
    {return x <= dificulty;}
    virtual void Move() = 0;

protected:
    int dificulty;
    int chill;
    int rage;
    const int way;
    int actual_possition;
};

#endif // ANIMATRONT_H
