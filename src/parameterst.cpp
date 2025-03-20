#include "parameterst.h"

ParametersT::ParametersT(int ene, int act_night): energy{ene}, actual_hour{act_night}
{}

bool ParametersT::Tic()
{
    tic = tic_clock.getElapsedTime();
    if(tic.asMilliseconds() > 67)
    {
        Update_Energy();
        tic_clock.reset();
        return true;
    }
    else
        return false;
}


