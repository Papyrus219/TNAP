#include "light.h"

Light::Light(int dif, int way_len, std::vector<std::pair<int, int>> waya): AnimatronT(dif,way_len,waya)
{
}

void Light::Move(CamerasT& x, OfficeT& y)
{
    if(underdoor)
    {
        bool is_close{y.Door_status_check(1)};

        if(is_close)
            chill++;
        else
            rage++;

        if(rage>=3)
        {
            std::cerr << "Light Jumpscare!\n";
            rage = 0;
            chill = 0;
            actual_possition = 3;
            underdoor = false;
            y.Doors[1].Used_variants[2] = &y.Doors[1].Sprites_variants[2];
        }
        else if(chill>=3)
        {
            rage = 0;
            chill = 0;
            actual_possition = 3;
            underdoor = false;
            y.Doors[0].Used_variants[2] = &y.Doors[0].Sprites_variants[2];
        }
    }
    else
    {
        std::srand(time(NULL));

        if(Move_check(rand()%20))
        {
            std::cerr << "Light Move!\n";
            actual_possition++;

            if(actual_possition==way_length)
            {
                if(x.used_Variants[10]==x.Variants[10][1])
                    x.used_Variants[10]=x.Variants[10][0];
                else
                    x.used_Variants[10]=x.Variants[10][2];

                y.Doors[1].Used_variants[2] = &y.Doors[0].Sprites_variants[4];
                underdoor=true;

                if(y.Door_light_check(0))
                    y.Doors[1].sprite.setTextureRect(*y.Doors[1].Used_variants[2]);
            }
            else
            {
                switch(actual_possition)
                {
                    case 1:
                        x.used_Variants[way[actual_possition].first] = x.Variants[way[actual_possition].first] [way[actual_possition].second];

                        if(x.used_Variants[0]==x.Variants[0][0])
                            x.used_Variants[0]=x.Variants[0][3];
                        else if(x.used_Variants[0]==x.Variants[0][1])
                            x.used_Variants[0]=x.Variants[0][6];
                        else if(x.used_Variants[0]==x.Variants[0][2])
                            x.used_Variants[0]=x.Variants[0][4];
                        else
                            x.used_Variants[0]=x.Variants[0][7];
                        break;
                    case 4:
                        if(rand()%2)
                            actual_possition = 3;

                        x.used_Variants[way[actual_possition].first] = x.Variants[way[actual_possition].first] [way[actual_possition].second];
                        x.used_Variants[way[actual_possition-1].first] = x.Variants[way[actual_possition-1].first][0];
                        break;
                    case 5:
                        if(x.used_Variants[10]==x.Variants[10][0])
                            x.used_Variants[10]=x.Variants[10][1];
                        else
                            x.used_Variants[10]=x.Variants[10][3];

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
