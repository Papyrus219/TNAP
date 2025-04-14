#include "bot.h"

Bot::Bot(std::string path_audio, int dif, int way_len, std::vector<int> waya): AnimatronT{path_audio,dif, way_len, waya}
{
    AnimatronT::Possitions[8]+=5;
}

std::vector<int> Bot::Move(OfficeT &x)
{
    std::srand(time(NULL));
    std::vector<int> tmp{};

    if(Move_check(rand()%20))
    {
        audio.play();
        actual_possition++;

        if(actual_possition == 5)
        {
            if(!x.Door_status_check(0))
            {
                std::cerr << "Bot jumpscare!\n";
                error a;
                throw(a);
            }

            actual_possition = 1;
        }

        if(x.actual_camera_on != 3)
        {
            std::cerr << "Bot moved! " << dificulty << "\n";

            tmp.push_back(3);
            tmp.push_back(actual_possition);
            tmp.push_back(-1);
            tmp.push_back(-1);
        }

    }

    return tmp;
}
