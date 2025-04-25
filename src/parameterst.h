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

class OfficeT;
class CamerasT;
class MenuT;

class ParametersT
{
public:
    ParametersT(std::string background_path, std::string start_night_path, int ene, int act_night, std::string path, int phones, int strikes, int stories, std::string button_path, sf::Vector2f button_poss, std::pair<int,int> se); //This function constructor.
    ParametersT() = default;

    TelephoneT phone{};

    bool stars[3];
    int stars_amount;
    bool hard_mode{};

    int Send_Hour()
    {return actual_hour;}
    int Send_Night()
    {return actual_night;}
    int Send_Energy()
    {return energy;}
    bool Send_Custom()
    {return custom_night;}
    void Update_Power_Ussage(std::vector<int> x); //This function update energy used when for example door closed.
    void Update_Energy() //This function change the energy every tic.
    {energy-=power_ussage;}

    void Hour_Passed()
    {actual_hour++;}

    void Load_Night(); //This function load night from file.

    void New_Night(std::vector<AnimatronT*> x, OfficeT &y, std::vector<int> custom_dif = {-69});
    //This function set all animatrons agressy, and reset power every time new night started.
    void Half_Time(std::vector<AnimatronT*> x);
    void Hard_mode(std::vector<AnimatronT*> x);

    void save();

    int Tic(MenuT &men, OfficeT &x, CamerasT &y, std::vector<AnimatronT*> z);


private:
    int power_ussage{1};
    int energy{};
    int actual_hour{};
    int actual_night{};
    bool custom_night{};
    sf::Clock tic_clock{};
    sf::Clock time_clock{};
    sf::Time tic{};
    sf::Time hour{};

    sf::SoundBuffer buffer{};
    sf::Sound start_night{buffer};
    sf::Music background{};

    friend class MenuT;
};

#endif // PARAMETERST_H
