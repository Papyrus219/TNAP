#include "officet.h"
#include<iostream>

OfficeT::OfficeT(sf::Vector2u window_size, std::string window_name,std::string office_path, std::string door_path, std::string button_path, std::string camera_button_path, int doors_amount, int buttons_amount, std::vector<sf::Vector2f> Door_possition, std::vector<sf::Vector2f> Buttons_possition, sf::Vector2f camera_button_possition) : Door_status{}, power_usage{1}
{
    window = new sf::RenderWindow;
    window->create(sf::VideoMode(window_size), window_name);

    for(int i=0;i<doors_amount;i++)
        Doors.push_back(DoorT {door_path, Door_possition[i], 5});
    for(int i=0;i<buttons_amount;i++)
    {
        Door_Buttons.push_back(Door_ButtonT {button_path, {Buttons_possition[i].x,Buttons_possition[i].y},&Doors[i]});
        Light_Buttons.push_back(Light_ButtonT {button_path, {Buttons_possition[i].x,Buttons_possition[i].y+100},&Doors[i]});
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

void OfficeT::Scroll()
{
    sf::Vector2f x{sf::Mouse::getPosition(*window)};

    if(Scroll_Hitbox[0].getGlobalBounds().contains(x))
    {
        if(view.getCenter().x > 300)
            view.move({-0.4,0});
    }
    else if(Scroll_Hitbox[1].getGlobalBounds().contains(x))
    {
        if(view.getCenter().x<900)
            view.move({0.4,0});
    }
}

void OfficeT::Clicked()
{
    window->setView(view);
    sf::Vector2f MousePos{window->mapPixelToCoords(sf::Mouse::getPosition(*window))};

    for(int i=0;i<Light_Buttons.size();i++)
    {
        if(Light_Buttons[i].Clicked(MousePos))
        {
            return;
        }
    }

    for(int i=0;i<Door_Buttons.size();i++)
    {
        if(Door_Buttons[i].Clicked(MousePos))
        {
            Door_status[i] = Doors[i].Get_if_close();
            return;
        }
    }

    window->setView(window->getDefaultView());
}


void OfficeT::Render()
{
    window->clear();

    window->setView(view);
    window->draw(sprite);
    for(int i=0;i<Doors.size();i++)
        window->draw(Doors[i].sprite);
    for(int i=0;i<Light_Buttons.size();i++)
        window->draw(Light_Buttons[i].sprite);
    for(int i=0;i<Door_Buttons.size();i++)
        window->draw(Door_Buttons[i].sprite);

    window->setView(window->getDefaultView());
    for(int i=0;i<2;i++)
        window->draw(Scroll_Hitbox[i]);

    window->display();
}

OfficeT::~OfficeT()
{
    delete window;
}
