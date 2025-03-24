#ifndef PARAMETERST_H
#define PARAMETERST_H

#include<SFML/System.hpp>
#include<iostream>

/*
 * So this class is for managment of basic varebles.
 *
 * It's for example track how much energy we use, wich hour it is.
 * This also send thouse informations by functions to other clasess.
 */

class ParametersT
{
public:
    ParametersT(int ene, int act_night); //This function constructor.

    int Send_Hour()
    {return actual_hour;}
    int Send_Night()
    {return actual_night;}
    int Send_Energy()
    {return energy;}

    void Update_Power_Ussage(int x); //This function update energy used when for example door closed.
    void Update_Energy() //This function change the energy every tic.
    {std::cerr << (energy-=power_ussage) << '\n';}

    void Hour_Passed()
    {actual_hour++;}

    void Load_Night(); //This function load night from file.
    void New_Night(); //This function set all animatrons agressy, and reset power every time new night started.

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
