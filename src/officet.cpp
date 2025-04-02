#include "officet.h"
#include"parameterst.h"
#include<iostream>

OfficeT::OfficeT(sf::Vector2u window_size, std::string window_name,std::string office_path, std::string door_path, std::string button_path, std::string camera_button_path, int doors_amount, int buttons_amount, std::vector<sf::Vector2f> Door_possition, std::vector<sf::Vector2f> Buttons_possition, sf::Vector2f camera_button_possition) : power_usage{1}, cam_button{camera_button_path,camera_button_possition,{1000,75}} //Constructor of OfficeT.
{
    window = new sf::RenderWindow; //We alocate memory to render window.
    window->create(sf::VideoMode(window_size), window_name); //We name window, and define its size.

    for(int i=0;i<doors_amount;i++) //For value of argument we push to vector coresponding amount of doors.
        Doors.push_back(DoorT {door_path, Door_possition[i], 5}); //We push back to vector.
        for(int i=0;i<buttons_amount;i++) //For value of buttons amount we also make door_button and light_button.
        {
            Door_Buttons.push_back(Door_ButtonT {button_path, {Buttons_possition[i].x,Buttons_possition[i].y},&Doors[i]});
            Light_Buttons.push_back(Light_ButtonT {button_path, {Buttons_possition[i].x,Buttons_possition[i].y+100},&Doors[i]});
        }

        float x{static_cast<float>((40.0/100.0)*window_size.x)}; //We calculate 40% od screen x size and convert it to float.
        float y{static_cast<float>(window_size.y)}; //We convert screen y size to float.

        Scroll_Hitbox[0] = sf::RectangleShape({x,y}); //We make 2 hitboxes, which our calculated values.
        Scroll_Hitbox[0].setFillColor(sf::Color::Transparent); //We make them Transparent.
        Scroll_Hitbox[0].setPosition({0,0}); //And position in coresponding place.
        Scroll_Hitbox[1] = sf::RectangleShape({x,y});
        Scroll_Hitbox[1].setFillColor(sf::Color::Transparent);
        Scroll_Hitbox[1].setPosition({static_cast<int>(window_size.x)-x,0});

        if(!texture.loadFromFile(office_path)) //We load texture of office.
            std::cout << "Failed to load texture of office.\n";

    sprite.setTexture(texture,true); //We set texture to office sprite (We gonna draw on screen this one.

    view = sf::View{{static_cast<float>(window_size.x)*0.5f, static_cast<float>(window_size.y)*0.5f} , {static_cast<float>(window_size.x)*0.5f, static_cast<float>(window_size.y)}};
    //We make view, to can do scroll effect.
}

void OfficeT::Scroll() //Scroll function.
{
    sf::Vector2f x{sf::Mouse::getPosition(*window)}; //We get mouse possition from office window.

    if(Scroll_Hitbox[0].getGlobalBounds().contains(x)) //We check if mouse is in first scroll hitbox:
    {
        if(view.getCenter().x > 300) //If yes and its not on border:
            view.move({-0.4,0}); //We scroll.
    }
    else if(Scroll_Hitbox[1].getGlobalBounds().contains(x)) //We check if mouse is in second scroll hitbox.
    {
        if(view.getCenter().x<900) //If yes and its not on border:
            view.move({0.4,0}); //We scroll.
    }
}

bool OfficeT::Camera_Open(CamerasT &x) //Function to open camera.
{
    sf::Vector2f MousePos{sf::Mouse::getPosition(*window)}; //We get mouse possition on window screen.

    if(cam_button.sprite.getGlobalBounds().contains(MousePos)) //If mouse is in camera button sprite.
    {
        x.Open(); //If yes we open cameras.
        return true; //and we return true, that we sucess to open camera.
    }

    return false; //If its not in camera button sprite we return false.
}

void OfficeT::Clicked(ParametersT x) //Function that check wich button (Or nose, was Clicked).
{
    window->setView(view); //We set view, to hitboxes was check right.
    sf::Vector2f MousePos{window->mapPixelToCoords(sf::Mouse::getPosition(*window))}; //We get mouse possition, from office screen (including view change).

    for(int i=0;i<Light_Buttons.size();i++) //We check each of light_button:
    {
        if(Light_Buttons[i].Clicked(MousePos)) //If one of it was clicked:
        {
            Door_light_status[i] = Doors[i].Get_if_Light(); //We update door status.

            if(Door_light_status[i]) //We update power usage after ligtning up/down door.
                Update_Energy_Usage(2);
            else
                Update_Energy_Usage(-2);

            return; //And end function.
        }
    }

    for(int i=0;i<Door_Buttons.size();i++) //We check each of door_button:
    {
        if(Door_Buttons[i].Clicked(MousePos)) //If one of it was clicked:
        {
            Door_close_status[i] = Doors[i].Get_if_close(); //We update door status.

            if(Door_close_status[i]) //We update power usage after closing/opening door.
                Update_Energy_Usage(4);
            else
                Update_Energy_Usage(-4);

            return; //And we end function.
        }
    }

    x.phone.Clicked(MousePos);

    window->setView(window->getDefaultView()); //We return to default view. (Just in case.)
}

void OfficeT::Update_Door_texture()
{
    for(int i=0;i<2;i++)
        Doors[i].sprite.setTextureRect(Doors[i].Used_variants[Doors[i].Get_texure()]);
}


void OfficeT::Render(ParametersT &x, CamerasT &y) //Function that draw everything in office window.
{
    window->clear(); //We clear window.

    window->setView(view); //We set view, to draw things that should scroll:
    window->draw(sprite); //We draw background.

    Update_Door_texture();
    for(int i=0;i<Doors.size();i++) //We draw each door.
    {
        window->draw(Doors[i].sprite);
    }
    for(int i=0;i<Light_Buttons.size();i++) //We draw each light_button.
        window->draw(Light_Buttons[i].sprite);
    for(int i=0;i<Door_Buttons.size();i++) //We draw each door_button.
        window->draw(Door_Buttons[i].sprite);

    window->setView(window->getDefaultView()); //We set back default view to draw interface.
    for(int i=0;i<2;i++)
        window->draw(Scroll_Hitbox[i]); //We draw each scroll hitbox.

        if(y.camera_window==nullptr) //If camera is close:
            window->draw(cam_button.sprite); //We draw camera button.

            window->draw(x.phone.button.sprite);

            Render_Stats(x); //We call function that draw all stats (energy, hour, etc...).

            window->display(); //We display everything we draw.
}

void OfficeT::Render_Stats(ParametersT &x) //Funtion that draw all stats on screen (energy, hour, etc...).
{
    sf::Font comic_sans; //We define font.
    if(!comic_sans.openFromFile("../../img/fonts/Comic Sans MS.ttf")) //We open font from files.
    {
        std::cout << "Error! Fail to load font!\n";
    }

    sf::Text Battery_txt{comic_sans}; //We set font to battery text.
    sf::Text Hour_txt{comic_sans}; //We set font to Hour text.

    Battery_txt.setString("Power: " + std::to_string(x.Send_Energy()/7) + "%"); //We set string to Battery text. (We take value from parametersT.
    Battery_txt.setPosition({1000,10}); //We set possition of it.
    Battery_txt.setFillColor(sf::Color::Blue); //And color.

    Hour_txt.setString(std::to_string((x.Send_Hour())? x.Send_Hour() : 12) + " AM"); //We set string to Hour text. (We take value from parametersT.
    Hour_txt.setPosition({20,10}); //We set possition of it.
    Hour_txt.setFillColor(sf::Color::Blue); //And color.

    window->draw(Battery_txt); //Finaly we draw both texts on screen.
    window->draw(Hour_txt);
}


OfficeT::~OfficeT() //Destructor, its free memory.
{
    delete window;
}
