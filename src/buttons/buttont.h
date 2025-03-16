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
    ButtonT(std::string path, std::pair<int,int> poss, std::pair<int,int> se = {50,50}); //Standart constructor for button.
    ButtonT(ButtonT &); //Copy constructor
    ButtonT(ButtonT &&); //MOve constructor

    sf::Sprite *actual_sprite{};

    virtual bool Clicked() {return false;}; //Standart virtual fuction. This is abstract class so its empty;

    virtual ~ButtonT(){};

protected:
    std::pair<int,int> possition {}; //Actual possition.
    std::pair<int,int> size {}; //Actual size;
    sf::Texture texture {}; //Two textures:: of and on.
    sf::Sprite Sprites[2]{sf::Sprite(texture),sf::Sprite(texture)}; //Sprites wich we gonna show in screen.
};

#endif // BUTTONT_H
