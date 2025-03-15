#ifndef BOT_H
#define BOT_H

#include"animatront.h"

class Bot: public AnimatronT
{
public:
    void Move() override;
};

#endif // BOT_H
