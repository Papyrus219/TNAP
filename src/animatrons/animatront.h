#ifndef ANIMATRONT_H
#define ANIMATRONT_H

#include<SFML/Audio.hpp>
#include<iostream>
#include<vector>
#include"../camerast.h"
#include"../officet.h"

struct jumpscare
{
    jumpscare(int ani)
    {who = ani;}

    int who{};
};

class AnimatronT
{
public:
    AnimatronT(std::string path_audio, int dif, int way_leng, std::vector<int> waya);

    static std::vector<int> Possitions;
    bool Move_check(int x); //We check if we can move.
    virtual std::vector<int> Move(OfficeT &x) = 0;

protected:
    int dificulty{};
    int chill{};
    int rage{};
    int actual_possition{};
    std::vector<int> way;
    const int way_length;
    bool underdoor{};
    sf::SoundBuffer buffer;
    sf::Sound audio;

    friend class ParametersT;
};

#endif // ANIMATRONT_H
