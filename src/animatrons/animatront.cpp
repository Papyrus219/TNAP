#include "animatront.h"


std::vector<int> AnimatronT::Possitions(11,0);

AnimatronT::AnimatronT(int dif, int way_leng, std::vector<int> waya): dificulty{dif},way{waya},way_length{way_leng}
{

}

bool AnimatronT::Move_check ( int x )
{
    if(x <= dificulty)
        return true;
    else
        return false;
}
