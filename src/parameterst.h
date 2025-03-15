#ifndef PARAMETERST_H
#define PARAMETERST_H


class ParametersT
{
public:
    ParametersT();

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

private:
    int power_ussage;
    int energy;
    int actual_hour;
    int actual_night;
};

#endif // PARAMETERST_H
