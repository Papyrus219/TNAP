#include "mememan.h"

Mememan::Mememan(std::string path_audio, std::string path, sf::Vector2f pos, std::pair<int,int> se, int dif, int path_len, std::vector<int> waya): AnimatronT{path_audio,dif, path_len, waya}, button{path, pos, se}
{
    AnimatronT::Possitions[8] += 7;

    //button.sprite.setTextureRect(button.);
}

std::vector<int> Mememan::Move(OfficeT &x)
{
    srand(time(NULL));
    std::vector<int> tmp{-1,-1};

    if(Move_check(rand()%20))
    {
        std::cerr << "Mememan move! " << dificulty << "\n";
        actual_possition++;
    }

    tmp.push_back(4);
    switch(actual_possition)
    {
        case 0:
            tmp.push_back(0);
            break;
        case 1:
            audio.play();
            tmp.push_back(1);
            break;
        case 2:
            rage++;
            if(rage >= 3)
            {
                std::cerr << "Mememan jumpscare!\n";
                jumpscare a{1};
                throw a;
                tmp.push_back(0);
            }
            break;
    }

    return tmp;
}
