#ifndef LIGHT_H
#define LIGHT_H

#include"animatront.h"

class Light: public AnimatronT
{
public:
    Light(int dif, int way_len, std::vector<std::pair<int,int>> waya);

    void Move(CamerasT &x, OfficeT &y) override;
};

#endif // LIGHT_H
