#ifndef BOT_H
#define BOT_H

#include"animatront.h"
#include"../camerast.h"

class Bot: public AnimatronT
{
public:
    Bot(int dif, int way_len, std::vector<std::pair<int,int>> waya);

    void Move(CamerasT &x, OfficeT &y) override;
};

#endif // BOT_H
