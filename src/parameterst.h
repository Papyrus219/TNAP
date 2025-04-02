#ifndef PARAMETERST_H
#define PARAMETERST_H

#include<SFML/System.hpp>
#include"animatrons/animatront.h"
#include"telephone.h"
#include<vector>

/*
 * So this class is for managment of basic varebles.
 *
 * It's for example track how much energy we use, wich hour it is.
 * This also send thouse informations by functions to other clasess.
 */

class ParametersT
{
public:
    ParametersT(int ene, int act_night, std::string path, int phones, int strikes, std::string button_path, sf::Vector2f button_poss, std::pair<int,int> se); //This function constructor.

    TelephoneT phone;

    int Send_Hour()
    {return actual_hour;}
    int Send_Night()
    {return actual_night;}
    int Send_Energy()
    {return energy;}

    void Update_Power_Ussage(std::vector<int> x); //This function update energy used when for example door closed.
    void Update_Energy() //This function change the energy every tic.
    {energy-=power_ussage;}

    void Hour_Passed()
    {actual_hour++;}

    void Load_Night(); //This function load night from file.

    void New_Night(std::vector<AnimatronT*> x);
    //This function set all animatrons agressy, and reset power every time new night started.
    void Half_Time(std::vector<AnimatronT*> x);

    bool Tic(std::vector<AnimatronT*> x);


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
