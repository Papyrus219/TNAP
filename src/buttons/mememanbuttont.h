#ifndef MEMEMANBUTTONT_H
#define MEMEMANBUTTONT_H

#include"buttont.h"

class MememanButtonT: public ButtonT
{
public:
    MememanButtonT(std::string path, sf::Vector2f possition, std::pair<int,int> size);

    bool Clicked(sf::Vector2f x) override {return true;};
};

#endif // MEMEMANBUTTONT_H
