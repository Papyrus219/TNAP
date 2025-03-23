#include "parameterst.h"
#include<iostream>

ParametersT::ParametersT(int ene, int act_night): energy{ene}, actual_hour{act_night}
{}

bool ParametersT::Tic()
{
    tic = tic_clock.getElapsedTime();

    if(tic.asMilliseconds() > 2478) //If this valoue passed tic happen. (Its so random to game be little less predictibile.
    {
        Update_Energy();
        tic_clock.restart(); //We restart clock.
        std::cerr << "TIC!\n"; //Debug shit.
        return true;
    }
    else
        return false;
}


