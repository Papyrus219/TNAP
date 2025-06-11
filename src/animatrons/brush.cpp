#include "brush.h"

Brush::Brush(std::string path_audio, int dif, int way_len, std::vector<int> waya): AnimatronT{path_audio,dif,way_len,waya}
{
    AnimatronT::Possitions[waya[0]]+=3;
}

std::vector<int> Brush::Move(OfficeT &x)
{
    std::vector<int> tmp{};
    std::srand(time(NULL));

    if(underdoor)
    {
        if(actual_possition == 3)
        {
            if(x.Door_light_check(1))
            {
                chill++;
                std::cerr << "Chill\n";
            }
            else
            {
                rage++;
                std::cerr << "No chill\n";
            }

            if(rage >= 3)
            {
                jumpscare a{4};
                throw a;
            }
            if(chill >=3)
            {
                actual_possition++;
                Possitions[10]-=3;
                tmp.push_back(10);
                tmp.push_back((Possitions[10] == 2)? 1 : 0);

                Possitions[9]+=3;
                tmp.push_back(9);
                tmp.push_back((Possitions[9] == 4)? 3 : 2);
                chill = 0;
                rage = 0;
            }
        }
        else if(actual_possition == 4)
        {
            if(x.Door_light_check(0))
            {
                std::cerr << "Chill\n";
                chill++;
            }
            else
            {
                std::cerr << "No chill\n";
                rage++;
            }

            if(rage >= 3)
            {
                jumpscare a{4};
                throw a;
            }
            if(chill >=3)
            {
                actual_possition = 2;
                Possitions[9]-=3;
                tmp.push_back(9);
                tmp.push_back((Possitions[9] == 1)? 1 : 0);

                tmp.push_back(-1);
                tmp.push_back(-1);
                chill = 0;
                rage = 0;
                underdoor = false;
            }
        }
    }
    else
    {
        if(Move_check(rand()%20))
        {
            std::cerr << "BRUSH MOVED!\n";
            actual_possition++;
            if(actual_possition==1)
            {
                tmp.push_back(0);
                switch(Possitions[0])
                {
                    case 3:
                        tmp.push_back(7);
                        break;
                    case 4:
                        tmp.push_back(4);
                        break;
                    case 5:
                        tmp.push_back(5);
                        break;
                    case 6:
                        tmp.push_back(2);
                        break;
                }

                tmp.push_back(-1);
                tmp.push_back(-1);
            }
            else
            {
                if(actual_possition == 3)
                {
                    tmp.push_back(-1);
                    tmp.push_back(-1);

                    Possitions[10]+=3;
                    tmp.push_back(10);
                    tmp.push_back((Possitions[10] == 5)? 3 : 2);

                    underdoor = true;
                }
            }
        }

    }


    return tmp;
}
