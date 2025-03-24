#ifndef DOORT_H
#define DOORT_H

#include<SFML/Graphics.hpp>

class DoorT
{
public:
    DoorT(std::string path, sf::Vector2f poss, int sprite_amount, std::pair<int,int> se = {150,700}); //Standart contructor.
    DoorT(const DoorT &); //Copy constructor.

    sf::Sprite sprite{texture}; //Sprite to show on screen.
    std::vector<sf::IntRect> Sprites_variants{}; //Vector to Sprite.
    sf::IntRect *Used_variants[3]{}; // Array to pointer. (used ones)

    void Close(); //Function to call when door is close.
    void Open(); //Fuction to call when door is open.
    void Light_up(); //Function to call when door is light up.
    void Light_down(); //Function to call when door is light down.
    void Animatron_ahead();
    bool Get_if_close(){return Power_status;};
    bool Get_if_Light(){return Light_status;};

    ~DoorT(){}; //Destructor.

private:
    std::pair<int,int> size; //Actual size.
    sf::Vector2f possition; //Actual size.
    sf::Texture texture{};
    int status{};
    bool Power_status{};
    bool Light_status{};
};

#endif // DOORT_H
