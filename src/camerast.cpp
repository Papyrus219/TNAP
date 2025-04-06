#include "camerast.h"
#include "animatrons/mememan.h"
#include <iostream>

CamerasT::CamerasT(std::string path, std::string panel_path, std::pair<int,int> se, sf::Vector2f hit_box_size, int camera_acount, int textures_acount, std::vector<int> separator, std::vector<sf::Vector2f> hit_box_possitions): size{se}, camera_panel{panel_path,{10,10},{300,300},hit_box_size,hit_box_possitions} //Standart constructor.
{
    if(!texture.loadFromFile(path)) //We load texture of cameras.
        std::cerr <<  "Error! Fail to load cameras texture!\n";

    int limit{},y{},act{},act_counter{}; //We deine some Varibles, to can effective devide exture into pieces.
    std::vector<sf::IntRect> tmp{}; //Temporery vector.
    while(limit<textures_acount) //While we dont devide all textures:
    {
        for(int x=0;x<5;x++) //There is 5 in row:
        {
            tmp.push_back({{size.first*x, size.second*y}, {size.first, size.second}}); //We push one rectange to tmp vector.

            act_counter++; //We increase number of actual camera in set.
            if(act_counter == separator[act]) //If set is full:
            {
                Variants.push_back(tmp); //We push temporery vecotor to main one.
                tmp.clear(); //Clean temporery vecotor.

                act++; //Increase set number.
                act_counter = 0; //And reset number of element i  set.
            }

            limit++;
        }
        y++; //We change row.
    }

    for(int i=0;i<camera_acount;i++) //We for each camera we have we push first her variant from set as used one.
        used_Variants.push_back(Variants[i][0]);

    sprite.setTexture(texture,true); //We set texture to sprite.
    sprite.setTextureRect(used_Variants[0]); //We set camera to first.
}

void CamerasT::Open() //Function opening camera window.
{
    camera_window = new sf::RenderWindow; //We alocate Render window.
    camera_window->create(sf::VideoMode({1000,667}), "Cameras"); //We name it and set its resolution.

    sf::Image icon;
    if(!icon.loadFromFile("../../img/icon.png"))
    {
        std::cerr << "Error! Failed to load icon!";
    }

    camera_window->setIcon(icon);
}

void CamerasT::Close() //Function closing camera window.
{
    camera_window->close(); //We close window.
    delete camera_window; //For sure we free memory.
    camera_window = nullptr; //We set window pointer to nullptr. (For safety)
}

void CamerasT::Render(Mememan &x) //Function that draw everything in camera window.
{
    camera_window->clear(); //We clear camera window.

    if(act_camera == 4 && x.actual_possition == 1)
        x.button.sprite.setTextureRect(x.button.Sprites_Variants[1]);
    else
        x.button.sprite.setTextureRect(x.button.Sprites_Variants[0]);

    camera_window->draw(sprite); //We draw sprite of camrea.
    camera_window->draw(camera_panel.sprite); //We draw camera panel.
    for(int i=0;i<camera_panel.Hit_box.size();i++) //We draw hit boxes of camera panel. (To can change actual camera)
        camera_window->draw(camera_panel.Hit_box[i]);

    camera_window->draw(x.button.sprite);
    sprite.setTextureRect(used_Variants[act_camera]); //We set sprite rectangle to actual used variant, to refresh screen if animatron move.

    camera_window->display(); //We display all this on screen.
}

void CamerasT::Camera_change(Mememan &x) //Fuction that check if player click camera change hitbox and change camera.
{
    sf::Vector2f MousePos{sf::Mouse::getPosition(*camera_window)}; //We get mouse possition from camera window.

    if(act_camera == 4 && x.actual_possition == 1)
        if(x.button.sprite.getGlobalBounds().contains(MousePos))
        {
            x.actual_possition--;
            x.rage = 0;
            used_Variants[4] = Variants[4][0];
            return;
        }

        for(int i=0;i<camera_panel.Hit_box.size();i++) //We check if any hitbox was clicked:
        {
            if(camera_panel.Hit_box[i].getGlobalBounds().contains(MousePos))
            {
                sprite.setTextureRect(used_Variants[i]); //If yes we change camera tp coresponding one variant.
                act_camera = i; //We update number of actual camera.

                return;
            }
        }
}

void CamerasT::Animatron_Move(std::vector<int> x)
{
    if(x.size()==4)
    {
        if(x[1] != -1) used_Variants[x[0]] = Variants[x[0]][x[1]];
        if(x[3] != -1) used_Variants[x[2]] = Variants[x[2]][x[3]];
    }
}

