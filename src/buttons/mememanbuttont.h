#ifndef MEMEMANBUTTONT_H
#define MEMEMANBUTTONT_H

#include"buttont.h"

class MememanButtonT: public ButtonT
{
public:
    MememanButtonT(std::string path, std::pair<int,int> size, std::pair<int,int> possition);

    bool Clicked() override {return true;};
};

#endif // MEMEMANBUTTONT_H
