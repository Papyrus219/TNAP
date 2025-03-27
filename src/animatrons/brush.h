#ifndef BRUSH_H
#define BRUSH_H

#include"animatront.h"

class Brush: public AnimatronT
{
public:
    Brush(int dif, int way_len, std::vector<int> waya);
    std::vector<int> Move(OfficeT &x) override;
};

#endif // BRUSH_H
