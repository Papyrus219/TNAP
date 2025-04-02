#include "parameterst.h"
#include<iostream>


ParametersT::ParametersT(int ene, int act_night, std::string path, int phones, int strikes, std::string button_path, sf::Vector2f button_poss, std::pair<int,int> se): phone{path,phones,strikes, button_path, button_poss, se} ,energy{ene} ,actual_hour{0}, actual_night(act_night)
{
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
            else if(actual_hour==1) //Night end.
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
    phone.button.Set_sprite_variant(1);
    AnimatronT::Possitions = {6,0,0,0,0,0,0,0,0,0,0};

    for(auto el : x)
        el->actual_possition = 0;

    switch(actual_night)
    {
        case 0:
            x[0]->dificulty = 5;
            x[1]->dificulty = 3;
            x[2]->dificulty = -1;
            x[3]->dificulty = -1;
            x[4]->dificulty = -1;
            break;
        case 1:
            x[0]->dificulty = -1;
            x[1]->dificulty = -1;
            x[2]->dificulty = -1;
            x[3]->dificulty = -1;
            x[4]->dificulty = -1;
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
            x[2]->dificulty = -1;
            x[3]->dificulty = -1;
            x[4]->dificulty = -1;
            break;
        case 1:
            x[0]->dificulty = 11;
            x[1]->dificulty = 10;
            x[2]->dificulty = 12;
            x[3]->dificulty = 9;
            x[4]->dificulty = -1;
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
    
    phone.PhoneCalls[actual_night].play();
}

