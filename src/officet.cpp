#include "officet.h"
#include<iostream>

OfficeT::OfficeT(sf::Vector2u window_size, std::string window_name,std::string office_path, std::string door_path, std::string button_path, std::string camera_button_path, int doors_amount, int buttons_amount, std::vector<sf::Vector2f> Door_possition, std::vector<std::pair<int, int>> Buttons_possition, std::pair<int, int> camera_button_possition) : Door_status{}, power_usage{1}
{
    window = new sf::RenderWindow;
    window->create(sf::VideoMode(window_size), window_name);

    for(int i=0;i<doors_amount;i++)
        Doors.push_back(DoorT {door_path, Door_possition[i], 5});
    for(int i=0;i<buttons_amount;i++)
    {
        Buttons.push_back(Door_ButtonT {button_path, Buttons_possition[i]});
        Buttons.push_back(Light_ButtonT {button_path, {Buttons_possition[i].first,Buttons_possition[i].second+100}});
    }

    float x{static_cast<float>((40.0/100.0)*window_size.x)};
    float y{static_cast<float>(window_size.y)};

    Scroll_Hitbox[0] = sf::RectangleShape({x,y});
    Scroll_Hitbox[0].setFillColor(sf::Color::Transparent);
    Scroll_Hitbox[0].setPosition({0,0});
    Scroll_Hitbox[1] = sf::RectangleShape({x,y});
    Scroll_Hitbox[1].setFillColor(sf::Color::Transparent);
    Scroll_Hitbox[1].setPosition({static_cast<int>(window_size.x)-x,0});

    if(!texture.loadFromFile(office_path))
        std::cout << "Failed to load texture of office.\n";

    sprite.setTexture(texture,true);

    view = sf::View{{static_cast<float>(window_size.x)*0.5f, static_cast<float>(window_size.y)*0.5f} , {static_cast<float>(window_size.x)*0.5f, static_cast<float>(window_size.y)}};
}

void OfficeT::Render()
{
    window->clear();

    window->setView(view);
    window->draw(sprite);
    for(int i=0;i<Doors.size();i++)
        window->draw(Doors[i].sprite);
    //for(int i=0;i<Buttons.size();i++)
        //window->draw(*Buttons[i].actual_sprite);

    window->setView(window->getDefaultView());
    for(int i=0;i<2;i++)
        window->draw(Scroll_Hitbox[i]);

    window->display();
}

void OfficeT::Scroll()
{
    sf::Vector2f x{sf::Mouse::getPosition(*window)};

    if(Scroll_Hitbox[0].getGlobalBounds().contains(x))
    {
        if(view.getCenter().x > 300)
            view.move({-1,0});
    }
    else if(Scroll_Hitbox[1].getGlobalBounds().contains(x))
    {
        if(view.getCenter().x<900)
            view.move({1,0});
    }
}


OfficeT::~OfficeT()

{
    delete window;
}
