#ifndef DOORT_H
#define DOORT_H

#include<SFML/Graphics.hpp>

class DoorT
{
public:
    DoorT(std::string path, sf::Vector2f poss, int sprite_amount, std::pair<int,int> se = {150,700}); //Standart contructor.
    DoorT(const DoorT &); //Copy constructor.
    //DoorT(DoorT &&); //Move constructor.

    sf::Sprite sprite{texture}; //Sprite to show on screen.

    void Close() //Function to call when door is close.
    {sprite.setTextureRect(*Used_variants[0]);}
    void Open() //Fuction to call when door is open.
    {sprite.setTextureRect(*Used_variants[1]);}
    void Light_up() //Function to call when door is light up.
    {sprite.setTextureRect(*Used_variants[2]);}
    void Light_down() //Function to call when door is light down.
    {sprite.setTextureRect(*Used_variants[1]);}
    void Animatron_ahead();

    ~DoorT(){}; //Destructor.

private:
    std::pair<int,int> size; //Actual size.
    sf::Vector2f possition; //Actual size.
    sf::Texture texture{};
    std::vector<sf::IntRect> Sprites_variants{}; //Vector to Sprite.
    sf::IntRect *Used_variants[3]{}; // Array to pointer. (used ones)
};

#endif // DOORT_H
