#include "light.h"

Light::Light(std::string path_audio, int dif, int way_len, std::vector<int> waya): AnimatronT{path_audio,dif, way_len, waya}
{
    AnimatronT::Possitions[waya[0]]+=2;
}

std::vector<int> Light::Move(OfficeT &x)
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
            actual_possition = 2;
            x.Change_Door_Textures(2,2,1);
            under_door = false;
        }
        else if(rage == 3)
        {
            std::cerr << "Light Nate Jumpscare\n";
            error a;
            throw(a);
            actual_possition = 2;
            x.Change_Door_Textures(2,2,1);
            under_door = false;
        }

        return tmp;
    }
    else
    {
        if(Move_check(rand()%20))
        {

            std::cerr << "Light Nate move! " << dificulty << "\n";
            tmp.push_back(way[actual_possition]);

            if(actual_possition == 0)
            {
                switch(Possitions[way[actual_possition]])
                {
                    case 2:
                        tmp.push_back(7);
                        break;
                    case 3:
                        tmp.push_back(4);
                        break;
                    case 5:
                        tmp.push_back(6);
                        break;
                    case 6:
                        tmp.push_back(3);
                        break;
                }
            }
            else
            {
                if(Possitions[way[actual_possition]] !=2 && actual_possition == 5)
                    tmp.push_back(2);
                else
                    tmp.push_back(0);
            }

            Possitions[way[actual_possition]]-=2;
            actual_possition++;

            if(actual_possition == 4)
                if(rand()%2)
                    actual_possition = 2;

            if(actual_possition == 6)
            {
                audio.play();
                tmp.push_back(-1);
                tmp.push_back(-1);
                under_door = true;
                x.Change_Door_Textures(2,4,1);
                return tmp;
            }

            Possitions[way[actual_possition]]+=2;

            tmp.push_back(way[actual_possition]);
            if(Possitions[way[actual_possition]] != 2 && actual_possition == 5 )
                tmp.push_back(3);
            else
                tmp.push_back(1);
        }
    }

    return tmp;
}
