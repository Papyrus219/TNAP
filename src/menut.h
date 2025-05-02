#ifndef MENUT_H
#define MENUT_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "buttons/menu_buttont.h"
#include "parameterst.h"

class Custom_night_menuT;

class MenuT
{
public:
    MenuT(std::string menu_path, std::string button_path, std::string star_path, std::string background_path, std::string intro_path, std::string audio_path, int options_amount, std::vector<sf::Vector2f> pos, std::pair<int,int> se, std::string skip_button_path, sf::Vector2f skip_button_possition, std::pair<int,int> skip_button_se);
    MenuT() = default;

    sf::Texture texture{};
    sf::Texture buttons_texture{};
    sf::Texture star_texture{};
    sf::Sprite star_sprite{star_texture};
    sf::Sprite sprite{texture};
    sf::Font comic_sans{};
    sf::Text continue_number{comic_sans};
    sf::RenderWindow* window{};
    std::vector<Menu_ButtonT> butions{};
    ParametersT par{};
    bool custom_night{};

    sf::Music background_music;

    void open();
    void Render();
    void Click(Custom_night_menuT &x);
    void Newgame();
    void Continue();
    void Custom_night(Custom_night_menuT &x);
    void Exit();
    void gameplay(std::vector<int> custom_dif = {});
    void close();

    void Load_Text(std::string font_path, sf::Vector2f possition, int size=14);

    ~MenuT();
};

#endif // MENUT_H
