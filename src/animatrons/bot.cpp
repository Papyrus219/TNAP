#include "bot.h"

Bot::Bot(int dif, int way_len, std::vector<std::pair<int, int>> waya): AnimatronT(dif, way_len, waya)
{
}


void Bot::Move(CamerasT& x, OfficeT& y)
{
    if(x.act_camera != 3)
    {
        srand(time(NULL));
        if(Move_check(rand()%20))
        {
            actual_possition++;

            if(actual_possition >= way_length)
            {
                if(!y.Door_status_check(0))
                    std::cerr << "Bot Jumpscare!\n";
                actual_possition = 1;
            }
            else
            {
                x.used_Variants[way[actual_possition].first] = x.Variants[way[actual_possition].first] [way[actual_possition].second];
            }
        }
    }
}
