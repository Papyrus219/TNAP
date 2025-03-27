#ifndef PAPYRUS_H
#define PAPYRUS_H

class AnimatronT;
#include"animatront.h"

class Papyrus: public AnimatronT
{
public:
    Papyrus(int dif, int way_lenght, std::vector<int> waya);

    bool under_door{};

    std::vector<int> Move(OfficeT &x) override;

};

#endif // PAPYRUS_H
