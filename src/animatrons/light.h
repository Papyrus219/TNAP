#ifndef LIGHT_H
#define LIGHT_H

#include"animatront.h"

class Light: public AnimatronT
{
public:
    Light(int dif, int way_len, std::vector<int> waya);

    bool under_door{};

    std::vector<int> Move(OfficeT &x) override;
};

#endif // LIGHT_H
