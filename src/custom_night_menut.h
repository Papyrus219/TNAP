#ifndef CUSTOM_NIGHT_MENUT_H
#define CUSTOM_NIGHT_MENUT_H

#include "menut.h"


class Custom_night_menuT : public MenuT
{
public:
    Custom_night_menuT(MenuT *ma, std::string custom_night_path, sf::Vector2f se, std::vector<sf::Vector2f> hitbox_positions, std::vector<sf::Vector2f> text_positions, int dif);

    void open();
    void Render();
    bool Click();
    void Start();

    ~Custom_night_menuT();

private:
    sf::Font comic_sans;
    int animatron_amount;
    std::vector<int> Dificulties{};
    std::vector<sf::RectangleShape> Hitboxes;
    std::vector<sf::Text> agros;

    MenuT* master;
};

#endif // CUSTOM_NIGHT_MENUT_H
