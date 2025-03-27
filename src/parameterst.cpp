#include "parameterst.h"
#include<iostream>

ParametersT::ParametersT(int ene, int act_night): energy{ene}, actual_hour{act_night}
{
    //We start both clocks.
    tic_clock.start();
    time_clock.start();
}

bool ParametersT::Tic()
{
    tic = tic_clock.getElapsedTime();
    hour = time_clock.getElapsedTime();

    if(tic.asMilliseconds() > 6478) //If this valoue passed tic happen. (Its so random to game be little less predictibile.
    {
        Update_Energy();
        std::cerr << "Energy ussage: " << power_ussage << '\n';

        if(hour.asSeconds() >= 90) //We check if hour passed.
        {
            actual_hour++;
            time_clock.restart();

            if(actual_hour==7) //Night end.
            {
                std::cerr << "You finish night!\n";
                actual_hour = 0;
                actual_night++;
            }
        }

        tic_clock.restart(); //We restart clock.
        std::cerr << "TIC!\n"; //Debug shit.
        return true;
    }
    else
        return false;
}

void ParametersT::Update_Power_Ussage(std::vector<int> x)
{
    power_ussage = 1;
    for(auto el : x)
        power_ussage+=el;
}

