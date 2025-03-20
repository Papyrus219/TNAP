#ifndef PARAMETERST_H
#define PARAMETERST_H

#include<SFML/System.hpp>

class ParametersT
{
public:
    ParametersT(int ene, int act_night);

    int Send_Hour()
    {return actual_hour;}
    int Send_Night()
    {return actual_night;}
    int Send_Energy()
    {return energy;}

    void Update_Power_Ussage(int x);
    void Update_Energy()
    {energy-=power_ussage;}

    void Hour_Passed()
    {actual_hour++;}

    void Load_Night();
    void New_Night();

    bool Tic();

private:
    int power_ussage{1};
    int energy;
    int actual_hour{};
    int actual_night;
    sf::Clock tic_clock{};
    sf::Clock time_clock{};
    sf::Time tic{};
    sf::Time hour{};
};

#endif // PARAMETERST_H
