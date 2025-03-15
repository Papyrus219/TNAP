#ifndef DOORT_H
#define DOORT_H

#include<string>
#include<SFML/Graphics.hpp>

class DoorT
{
public:
    DoorT(std::string path, std::pair<int,int> size, std::pair<int,int> possition, int texture_amount); //Standart contructor.
    DoorT(const DoorT &); //Copy constructor.
    DoorT(DoorT &&); //Move constructor.

    void Close() //Function to call when door is close.
    {sprite.setTexture(*Textures_Used[0]);}
    void Open() //Fuction to call when door is open.
    {sprite.setTexture(*Textures_Used[1]);}
    void Light_up() //Function to call when door is light up.
    {sprite.setTexture(*Textures_Used[2]);}
    void Light_down() //Function to call when door is light down.
    {sprite.setTexture(*Textures_Used[3]);}

private:
    std::pair<int,int> size; //Actual size.
    std::pair<int,int> possition; //Actual size.
    sf::Sprite sprite; //Sprite to show on screen.
    sf::Texture* *Textures{}; //Pointer to pointers. We will alocate array of pointers in fututre.
    sf::Texture *Textures_Used[4]{}; // Array to pointer. (used ones)

    ~DoorT(); //Destructor.
};

#endif // DOORT_H
