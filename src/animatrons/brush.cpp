#include "brush.h"

Brush::Brush(int dif, int way_len, std::vector<int> waya): AnimatronT{dif,way_len,waya}
{
    AnimatronT::Possitions[waya[0]]+=3;
}

std::vector<int> Brush::Move(OfficeT &x)
{
    std::vector<int> tmp{};

    if(Move_check(rand()%20))
    {
        std::cerr << "Brush move!\n";
        tmp.push_back(way[actual_possition]);

        if(actual_possition == 0)
        {
            switch(Possitions[actual_possition])
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
        }
        else
        {
            if(actual_possition == 3 || actual_possition == 5)
            {
                if(Possitions[actual_possition] != 3)
                    tmp.push_back(1);
                else
                    tmp.push_back(0);
            }
            else
                tmp.push_back(-1);
        }

        Possitions[actual_possition]-=3;
        actual_possition++;

        if(actual_possition == 4 || actual_possition == 6)
        {
            tmp.push_back(-1);
            tmp.push_back(-1);

            if(actual_possition == 4)
            {
                if(!x.Door_status_check(1))
                {
                    error a;
                    throw(a);
                    std::cerr << "Brush Jumpscare!\n";
                }
            }
            else
            {
                if(!x.Door_status_check(0))
                {
                    error a;
                    throw(a);
                    std::cerr << "Brush Jumpscare!\n";
                    actual_possition = 2;
                }
            }

            return tmp;
        }

        Possitions[actual_possition]+=3;

        tmp.push_back(way[actual_possition]);

        if(actual_possition == 3 || actual_possition == 5)
        {
            if(Possitions[actual_possition] != 3)
                tmp.push_back(3);
            else
                tmp.push_back(2);
        }
        else
            tmp.push_back(-1);
    }

    return tmp;
}
