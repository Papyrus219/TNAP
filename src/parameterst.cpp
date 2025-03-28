#include "parameterst.h"
#include<iostream>

ParametersT::ParametersT(int ene, int act_night, std::string path, int phones, int strikes, std::vector<AnimatronT*> x): phone{path,phones,strikes} ,energy{ene}, actual_hour{act_night}
{
    New_Night(x);
    //We start both clocks.
    tic_clock.start();
    time_clock.start();
}

bool ParametersT::Tic(std::vector<AnimatronT*> x)
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

            if(actual_hour == 3)
                Half_Time(x);
            else if(actual_hour==7) //Night end.
            {
                std::cerr << "You finish night!\n";
                actual_hour = 0;
                actual_night++;
                New_Night(x);
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

void ParametersT::New_Night(std::vector<AnimatronT*> x)
{
    switch(actual_night)
    {
        case 0:
            x[0]->dificulty = 5;
            x[1]->dificulty = 3;
            x[2]->dificulty = 0;
            x[3]->dificulty = 0;
            x[4]->dificulty = 0;
            break;
        case 1:
            x[0]->dificulty = 7;
            x[1]->dificulty = 4;
            x[2]->dificulty = 7;
            x[3]->dificulty = 6;
            x[4]->dificulty = 0;
            break;
        case 2:
            x[0]->dificulty = 7;
            x[1]->dificulty = 6;
            x[2]->dificulty = 5;
            x[3]->dificulty = 7;
            x[4]->dificulty = 10;
            break;
    }

    phone.PhoneCalls[actual_night].play();
}

void ParametersT::Half_Time(std::vector<AnimatronT*> x)
{
    switch(actual_night)
    {
        case 0:
            x[0]->dificulty = 7;
            x[1]->dificulty = 6;
            x[2]->dificulty = 0;
            x[3]->dificulty = 0;
            x[4]->dificulty = 0;
            break;
        case 1:
            x[0]->dificulty = 11;
            x[1]->dificulty = 10;
            x[2]->dificulty = 12;
            x[3]->dificulty = 9;
            x[4]->dificulty = 0;
            break;
        case 2:
            x[0]->dificulty = 15;
            x[1]->dificulty = 15;
            x[2]->dificulty = 15;
            x[3]->dificulty = 15;
            x[4]->dificulty = 15;
            break;
        default:
            for(auto el : x)
                el->dificulty*=2;
    }
}
