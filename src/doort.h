#ifndef DOORT_H
#define DOORT_H

#include<SFML/Graphics.hpp>

class DoorT
{
public:
    DoorT(std::string path, std::pair<int,int> poss, int sprite_amount, std::pair<int,int> se = {150,700}); //Standart contructor.
    DoorT(const DoorT &){}; //Copy constructor.
    DoorT(DoorT &&); //Move constructor.

    sf::Sprite *actual_sprite; //Sprite to show on screen.

    void Close() //Function to call when door is close.
    {actual_sprite = Sprites_Used[0];}
    void Open() //Fuction to call when door is open.
    {actual_sprite = Sprites_Used[1];}
    void Light_up() //Function to call when door is light up.
    {actual_sprite = Sprites_Used[2];}
    void Light_down() //Function to call when door is light down.
    {actual_sprite = Sprites_Used[1];}
    void Animatron_ahead();

    ~DoorT(){}; //Destructor.

private:
    std::pair<int,int> size; //Actual size.
    std::pair<int,int> possition; //Actual size.
    sf::Texture texture{};
    std::vector<sf::Sprite> Sprites{}; //Vector to Sprite.
    sf::Sprite *Sprites_Used[3]{}; // Array to pointer. (used ones)
};

#endif // DOORT_H
