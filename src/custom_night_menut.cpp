#include "custom_night_menut.h"

Custom_night_menuT::Custom_night_menuT(MenuT *ma , std::string custom_night_path, sf::Vector2f se, std::vector<sf::Vector2f> hitbox_positions, std::vector<sf::Vector2f> text_positions, int dif): master{ma}, Dificulties(dif,0)
{
    if(!texture.loadFromFile(custom_night_path))
    {
        std::cerr << "Error! Fail to load custom night texture!";
    }

    if(!comic_sans.openFromFile("../../img/fonts/Comic Sans MS.ttf")) //We open font from files.
    {
        std::cout << "Error! Fail to load font!\n";
    }

    for(int i=0;i<text_positions.size();i++)
    {
        sf::Text temp{comic_sans};
        temp.setFillColor(sf::Color::Magenta);
        temp.setPosition(text_positions[i]);
        temp.setString(std::to_string(Dificulties[i]));

        agros.push_back(temp);
    }

    sprite.setTexture(texture, true);;

    for(int i=0; i<hitbox_positions.size();i++)
    {
        sf::RectangleShape tmp{se};
        tmp.setPosition(hitbox_positions[i]);
        tmp.setFillColor(sf::Color::Transparent);

        Hitboxes.push_back(tmp);
    }
}

void Custom_night_menuT::open()
{
    window = new sf::RenderWindow;
    window->create(sf::VideoMode({1200,1000}), "Custom night");

    while(window->isOpen())
    {
        Render();
        if(const std::optional event = window->pollEvent()) //Hello
        {
            if (event->is<sf::Event::Closed>()) //Standard, we check if window is closed.
            {
                close();
                return ;
            }
            if(event->is<sf::Event::MouseButtonPressed>())
            {
                Click();
            }
        }
    }
}

void Custom_night_menuT::Render()
{
    if(window != nullptr)
    {
        window->clear();

        window->draw(sprite);
        for(auto el : Hitboxes)
        {
            window->draw(el);
        }
        for(auto el : agros)
        {
            window->draw(el);
        }

        window->display();
    }
}

void Custom_night_menuT::Click()
{
    sf::Vector2f MousePos{sf::Mouse::getPosition(*window)};

    for(int i=0;i<Hitboxes.size();i++)
    {
        if(Hitboxes[i].getLocalBounds().contains(MousePos))
        {
            if(i == Hitboxes.size()-1)
            {
                Start();
                return;
            }

            if(i%2)
            {
                if(Dificulties[i/2] < 8)
                    Dificulties[i/2]++;
            }
            else
            {
                if(Dificulties[i/2] > 0)
                    Dificulties[i/2]--;
            }

            agros[i/2].setString(std::to_string(Dificulties[i/2]));
        }
    }
}

void Custom_night_menuT::Start()
{

}

Custom_night_menuT::~Custom_night_menuT()
{
    close();
}





