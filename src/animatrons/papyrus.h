#ifndef PAPYRUS_H
#define PAPYRUS_H

class CameraT;
class AnimatronT;
#include"animatront.h"

class Papyrus: public AnimatronT
{
public:
    Papyrus(int dif, int way_lenght, std::vector<std::pair<int,int>> waya);

    void Move(CamerasT &x, OfficeT &y) override;

};

#endif // PAPYRUS_H
