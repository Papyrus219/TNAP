#ifndef MENUT_H
#define MENUT_H

#include<SFML/Graphics.hpp>
#include "buttons/menu_buttont.h"
#include "parameterst.h"

class MenuT
{
public:
    MenuT(std::string menu_path, std::string button_path, int options_amount, std::vector<sf::Vector2f> pos, std::pair<int,int> se, std::string skip_button_path, sf::Vector2f skip_button_possition, std::pair<int,int> skip_button_se);

    sf::Texture menu_texture{};
    sf::Texture buttons_texture{};
    sf::Sprite sprite{menu_texture};
    int stars{};

    sf::RenderWindow* window{};
    std::vector<Menu_ButtonT> butions{};
    ParametersT par;

    void open();
    void Render();
    void Click();
    void Newgame();
    void Continue();
    void Custom_night();
    void Exit();
    void gameplay();
    void close();

    ~MenuT();
};

#endif // MENUT_H
