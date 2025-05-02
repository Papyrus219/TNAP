#include "parameterst.h"
#include "menut.h"
#include<iostream>
#include<fstream>


ParametersT::ParametersT(std::string background_path, std::string start_night_path, int ene, int act_night, std::string path, int phones, int strikes, int stories, std::string button_path, sf::Vector2f button_poss, std::pair<int,int> se): phone{path,phones,strikes,stories, button_path, button_poss, se} ,energy{ene} ,actual_hour{0}, actual_night(act_night), start_night{buffer}, stars_amount{0},stars{false,false,false}
{
    //We start both clocks.
    tic_clock.start();
    time_clock.start();

    if(!buffer.loadFromFile(start_night_path))
    {
        std::cerr << "Error! Cant load background music!\n";
    }
    start_night.setBuffer(buffer);
    start_night.setVolume(20);

    if(!background.openFromFile(background_path))
    {
        std::cerr << "Error! Cant load background music!\n";
    }
    background.setVolume(70);
}

int ParametersT::Tic(MenuT &men, OfficeT &x, CamerasT &y, std::vector<AnimatronT*> z)
{
    tic = tic_clock.getElapsedTime();
    hour = time_clock.getElapsedTime();

    if(tic.asMilliseconds() > 6478) //If this valoue passed tic happen. (Its so random to game be little less predictibile.
    {
        Update_Energy();
        std::cerr << "Energy ussage: " << power_ussage << '\n';

        if(energy < 0)
        {
            x.Change_office_texuture(2);
            y.Close();
            x.Power_off();
        }

        if(hour.asSeconds() >= 90) //We check if hour passed.
        {
            actual_hour++;
            time_clock.restart();

            if(actual_hour == 3)
                Half_Time(z);
            else if(actual_hour>=6) //Night end.
            {
                std::cerr << "You finish night!\n";
                actual_hour = 0;
                if(actual_night < 3) actual_night++;

                if(custom_night == false)
                {
                    phone.Skiped+=phone.temp_Skiped;
                    save();
                }

                y.Close();

                x.end_night();

                time_clock.reset();
                tic_clock.reset();

                if(actual_night>=4 || custom_night==true)
                {
                    if(actual_night >= 4)
                    {
                        if(stars[0]==false)
                        {
                            stars_amount++;
                            stars[0] = true;
                            x.Ending(0);
                        }

                    }
                    if(custom_night)
                    {
                        if(stars[1]==false)
                        {
                            stars_amount++;
                            stars[1] = true;
                            x.Ending(1);
                        }
                    }
                    if(hard_mode)
                    {
                        if(stars[2]==false)
                        {
                            stars_amount++;
                            stars[2] = true;
                            x.Ending(2);
                        }
                    }

                     x.Close();
                    return -2;
                }

                men.gameplay();
                return -2;
            }
        }

        tic_clock.restart(); //We restart clock.
        std::cerr << "TIC!\n"; //Debug shit.
        return 1;
    }
    else
        return 0;
}

void ParametersT::Update_Power_Ussage(std::vector<int> x)
{
    power_ussage = 1;
    for(auto el : x)
        power_ussage+=el;
}

void ParametersT::New_Night(std::vector<AnimatronT*> x, OfficeT &y, std::vector<int> custom_dif)
{
    actual_hour = 0;
    hard_mode = false;

    energy = 700;
    phone.temp_Skiped = 0;

    if((custom_dif.empty()))
    {
        phone.button.Set_sprite_variant(1);
        AnimatronT::Possitions = {6,0,0,0,0,0,0,0,0,0,0};

        save();

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
                x[0]->dificulty = 7;
                x[1]->dificulty = 4;
                x[2]->dificulty = 7;
                x[3]->dificulty = 6;
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

        background.stop();
        start_night.play();

        y.start_night(*this);

        background.play();
        phone.PhoneCalls[actual_night].play();
    }
    else
    {
        std::cerr << "Chicken jokey!\n";
        custom_night = true;

        for(int i=0;i<custom_dif.size();i++)
        {
            x[i]->dificulty = (custom_dif[i]==0)? -1 : custom_dif[i];
        }

        background.stop();
        start_night.play();
        y.start_night(*this);
        background.play();
    }

    tic_clock.restart();
    time_clock.restart();

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
}

void ParametersT::save()
{
    std::ofstream save_file{"../../data/save.txt", std::ios::trunc};

    save_file << actual_night << ';' << phone.Skiped << ';' << stars_amount << ';';

    for(int i=0;i<3;i++)
        save_file << ((stars[i])? '1' : '0' ) << ';';

    save_file << '~';

    save_file.close();
}

void ParametersT::Hard_mode(std::vector<AnimatronT *> x)
{
    std::cerr << "HARD MODE!\n";
    hard_mode = true;

    for(auto el : x)
        el->dificulty=20;
}
