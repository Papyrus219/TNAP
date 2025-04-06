#include "animatront.h"


std::vector<int> AnimatronT::Possitions(11,0);

AnimatronT::AnimatronT(std::string path_audio, int dif, int way_leng, std::vector<int> waya): dificulty{dif},way{waya},way_length{way_leng},audio{buffer}
{
    if(!buffer.loadFromFile(path_audio))
    {
        std::cerr << "Error! Falied to load animatron audio!\n";
    }

    audio.setBuffer(buffer);
    audio.setVolume(5);
}

bool AnimatronT::Move_check ( int x )
{
    if(x <= dificulty)
        return true;
    else
        return false;
}
