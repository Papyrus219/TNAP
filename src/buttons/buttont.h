#ifndef BUTTONT_H
#define BUTTONT_H

#include<SFML/Graphics.hpp>
#include<string>

/*
 * Abstract class to be inheritance.
 */

class ButtonT
{
public:
    sf::Sprite sprite; //Sprite wich we gonna show in screen.

    ButtonT(std::string path, std::pair<int,int> size, std::pair<int,int> possition); //Standart constructor for button.
    ButtonT(ButtonT &); //Copy constructor
    ButtonT(ButtonT &&); //MOve constructor

    virtual bool Clicked(){}; //Standart virtual fuction. This is abstract class so its empty;

protected:
    sf::Texture texture[2]; //Two textures:: of and on.
    std::pair<int,int> possition; //Actual possition.
    std::pair<int,int> size; //Actual size;
};

#endif // BUTTONT_H
