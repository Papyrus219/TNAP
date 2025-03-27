#ifndef BOT_H
#define BOT_H

#include"animatront.h"

class Bot: public AnimatronT
{
public:
    Bot(int dif, int way_len, std::vector<int> waya);

    std::vector<int> Move(OfficeT &x) override;
};

#endif // BOT_H
