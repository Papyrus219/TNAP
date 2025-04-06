#include "papyrus.h"

Papyrus::Papyrus(std::string path_audio, int dif, int way_lenght, std::vector<int> waya): AnimatronT{path_audio,dif, way_lenght, waya}
{
    AnimatronT::Possitions[waya[0]]+=1;
}

std::vector<int> Papyrus::Move(OfficeT &x)
{
    std::srand(time(NULL));
    std::vector<int> tmp{};

    if(under_door)
    {
        if(x.Door_status_check(0))
            chill++;
        else
            rage++;

        if(chill == 3)
        {
            actual_possition = 1;
            x.Change_Door_Textures(2,2,0);
            under_door = false;
        }
        else if(rage == 3)
        {
            std::cerr << "Papyrus Jumpscare\n";
            error a;
            throw(a);
            actual_possition = 1;
            x.Change_Door_Textures(2,2,0);
            under_door = false;
        }

        return tmp;
    }
    else
    {
        if(Move_check(rand()%20))
        {
            std::cerr << "Papyrus move!\n";
            tmp.push_back(way[actual_possition]);

            if(actual_possition == 0)
            {
                switch(Possitions[way[actual_possition]])
                {
                    case 1:
                        tmp.push_back(7);
                        break;
                    case 3:
                        tmp.push_back(5);
                        break;
                    case 4:
                        tmp.push_back(6);
                        break;
                    case 6:
                        tmp.push_back(1);
                        break;
                }
            }
            else
            {
                if(Possitions[way[actual_possition]] != 1 && actual_possition == 4)
                    tmp.push_back(2);
                else
                    tmp.push_back(0);
            }

            Possitions[way[actual_possition]]-=1;
            actual_possition++;
            if(actual_possition == 5)
            {
                audio.play();
                tmp.push_back(-1);
                tmp.push_back(-1);
                under_door = true;
                x.Change_Door_Textures(2,3,0);
                return tmp;
            }

            Possitions[way[actual_possition]]+=1;

            tmp.push_back(way[actual_possition]);

            if(Possitions[way[actual_possition]] != 1 && actual_possition == 4)
                tmp.push_back(3);
            else
                tmp.push_back(1);
        }
    }

    return tmp;
}
