#include "brush.h"

Brush::Brush(int dif, int way_len): AnimatronT(dif, way_len, {{0,0}})
{}

void Brush::Move(CamerasT& x, OfficeT& y)
{
    srand(time(NULL));

    if(underdoor)
    {
        if(actual_possition == 4)
        {
            if(!y.Door_status_check(1))
                std::cerr << "Brush Jumpscare!\n";
        }
        else if(actual_possition == 6)
        {
            if(!y.Door_status_check(0))
                std::cerr << "Brush Jumpscare\n";
            actual_possition = 2;
        }

        underdoor = false;
    }
    else
    {
        if(Move_check(rand()%20))
        {
            std::cerr << "Brush move!\n";
            actual_possition++;

            switch(actual_possition)
            {
                case 1:
                    if(x.used_Variants[0] == x.Variants[0][0])
                        x.used_Variants[0] = x.Variants[0][2];
                    else if(x.used_Variants[0] == x.Variants[0][1])
                        x.used_Variants[0] = x.Variants[0][5];
                    else if(x.used_Variants[0] == x.Variants[0][3])
                        x.used_Variants[0] = x.Variants[0][4];
                    else
                        x.used_Variants[0] = x.Variants[0][7];
                    break;
                case 3:
                    if(x.used_Variants[10]==x.Variants[10][0])
                        x.used_Variants[10] = x.Variants[10][2];
                    else
                        x.used_Variants[10] = x.Variants[10][3];
                    break;
                case 4:
                    if(x.used_Variants[10]==x.Variants[10][2])
                        x.used_Variants[10] = x.Variants[10][0];
                    else
                        x.used_Variants[10] = x.Variants[10][1];

                    underdoor = true;
                    break;
                case 5:
                    if(x.used_Variants[9]==x.Variants[9][0])
                        x.used_Variants[9] = x.Variants[9][2];
                    else
                        x.used_Variants[9] = x.Variants[9][3];
                    break;
                case 6:
                    if(x.used_Variants[9]==x.Variants[9][2])
                        x.used_Variants[9] = x.Variants[9][0];
                    else
                        x.used_Variants[10] = x.Variants[10][1];

                    underdoor = true;
                    break;

            }
        }
    }
}
