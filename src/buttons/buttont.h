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
    ButtonT(std::string path, sf::Vector2f poss, std::pair<int,int> se); //Standart constructor for button.
    ButtonT() = default;
    ButtonT(ButtonT &); //Copy constructor
    ButtonT(ButtonT &&); //Copy constructor

    sf::Sprite sprite{texture}; //Sprite of button.
    int actual_variant{};

    virtual bool Clicked(sf::Vector2f x) = 0; //Standart virtual fuction. This is abstract class so its empty;

protected:
    sf::Vector2f possition {}; //Actual possition.
    std::pair<int,int> size {}; //Actual size;
    sf::Texture texture {}; //Two textures:: of and on.
    sf::IntRect Sprites_Variants[2]{}; //Sprites wich we gonna show in screen.
    bool status{}; //Boolian that storage if button is cliced or not.

    friend class ParametersT;
};

#endif // BUTTONT_H
