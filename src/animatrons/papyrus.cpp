#include "papyrus.h"

Papyrus::Papyrus(int dif, int way_len, std::vector<std::pair<int,int>> waya): AnimatronT(dif,way_len,waya)
{
}


void Papyrus::Move(CamerasT &x, OfficeT &y)//I am sorry for this function...
{
    if(underdoor)
    {
        bool is_close{y.Door_status_check(0)};

        if(is_close)
            chill++;
        else
            rage++;

        if(rage>=3)
        {
            std::cerr << "Papyrus Jumpscare!\n";
            rage = 0;
            chill = 0;
            actual_possition = 1;
            underdoor = false;
            y.Doors[0].Used_variants[2] = &y.Doors[0].Sprites_variants[2];
        }
        else if(chill>=3)
        {
            rage = 0;
            chill = 0;
            actual_possition = 1;
            underdoor = false;
            y.Doors[0].Used_variants[2] = &y.Doors[0].Sprites_variants[2];
        }
    }
    else
    {
        std::srand(time(NULL));

        if(Move_check(rand()%20))
        {
            std::cerr << "Papyrus Move!\n";
            actual_possition++;

            if(actual_possition==way_length)
            {
                if(x.used_Variants[9]==x.Variants[9][1])
                    x.used_Variants[9]=x.Variants[9][0];
                else
                    x.used_Variants[9]=x.Variants[9][2];

                y.Doors[0].Used_variants[2] = &y.Doors[0].Sprites_variants[3];
                underdoor=true;

                if(y.Door_light_check(0))
                    y.Doors[0].sprite.setTextureRect(*y.Doors[0].Used_variants[2]);

            }
            else
            {
                switch(actual_possition)
                {
                    case 1:
                        x.used_Variants[way[actual_possition].first] = x.Variants[way[actual_possition].first] [way[actual_possition].second];

                        if(x.used_Variants[0]==x.Variants[0][0])
                            x.used_Variants[0]=x.Variants[0][1];
                        else if(x.used_Variants[0]==x.Variants[0][2])
                            x.used_Variants[0]=x.Variants[0][5];
                        else if(x.used_Variants[0]==x.Variants[0][3])
                            x.used_Variants[0]=x.Variants[0][6];
                        else
                            x.used_Variants[0]=x.Variants[0][7];
                        break;
                    case 5:
                        if(x.used_Variants[9]==x.Variants[9][0])
                            x.used_Variants[9]=x.Variants[9][1];
                        else
                            x.used_Variants[9]=x.Variants[9][3];

                        x.used_Variants[way[actual_possition-1].first] = x.Variants[way[actual_possition-1].first][0];
                        break;
                    default:
                        x.used_Variants[way[actual_possition].first] = x.Variants[way[actual_possition].first] [way[actual_possition].second];
                        x.used_Variants[way[actual_possition-1].first] = x.Variants[way[actual_possition-1].first][0];
                        break;
                }
            }
        }
    }
}
