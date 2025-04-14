#ifndef MENUT_H
#define MENUT_H

#include<SFML/Graphics.hpp>
#include "buttons/menu_buttont.h"
#include "parameterst.h"

class Custom_night_menuT;

class MenuT
{
public:
    MenuT(std::string menu_path, std::string button_path, std::string background_path,std::string intro_path, int options_amount, std::vector<sf::Vector2f> pos, std::pair<int,int> se, std::string skip_button_path, sf::Vector2f skip_button_possition, std::pair<int,int> skip_button_se);
    MenuT() = default;

    sf::Texture texture{};
    sf::Texture buttons_texture{};
    sf::Sprite sprite{texture};
    sf::RenderWindow* window{};
    std::vector<Menu_ButtonT> butions{};
    ParametersT par{};
    bool custom_night{};

    void open();
    void Render();
    void Click(Custom_night_menuT &x);
    void Newgame();
    void Continue();
    void Custom_night(Custom_night_menuT &x);
    void Exit();
    void gameplay(std::vector<int> custom_dif = {});
    void close();

    ~MenuT();
};

#endif // MENUT_H
