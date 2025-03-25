#ifndef BRUSH_H
#define BRUSH_H

#include"animatront.h"

class Brush: public AnimatronT
{
public:
    Brush(int dif, int way_len);
    void Move(CamerasT &x, OfficeT &y) override{};
};

#endif // BRUSH_H
