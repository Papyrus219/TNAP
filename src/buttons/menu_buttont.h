#ifndef MENU_BUTTONT_H
#define MENU_BUTTONT_H

#include "buttont.h"

class MenuT;

class Menu_ButtonT : public ButtonT
{
public:

    Menu_ButtonT(std::string path, sf::Vector2f pos, std::pair<int,int> se);
};

#endif // MENU_BUTTONT_H
