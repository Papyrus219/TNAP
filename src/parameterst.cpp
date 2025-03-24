#include "parameterst.h"
#include<iostream>

ParametersT::ParametersT(int ene, int act_night): energy{ene}, actual_hour{act_night}
{
    time_clock.start();
    tic_clock.start();
}

void ParametersT::Update_Power_Ussage(int x)
{
    power_ussage=x;
}


bool ParametersT::Tic()
{
    tic = tic_clock.getElapsedTime();


    if(tic.asMilliseconds() > 6478) //If this valoue passed tic happen. (Its so random to game be little less predictibile.
    {
        Update_Energy();
        tic_clock.restart(); //We restart clock.
        std::cerr << "TIC!\n"; //Debug shit.

        hour = time_clock.getElapsedTime();
        std::cerr << hour.asSeconds() << " s!\n";
        if(hour.asSeconds() > 90)
        {
            actual_hour++;
            time_clock.restart();
        }

        return true;
    }
    else
        return false;
}


