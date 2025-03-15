#ifndef ANIMATRONT_H
#define ANIMATRONT_H

class AnimatronT
{
public:
    AnimatronT(int dif,int way_tmp);

    bool Move_check(int x) //We check if we can move.
    {return x <= dificulty;}
    virtual void Move(){};

protected:
    int dificulty;
    int chill;
    int rage;
    const int way;
    int actual_possition;
};

#endif // ANIMATRONT_H
