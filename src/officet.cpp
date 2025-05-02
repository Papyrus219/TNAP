#include "officet.h"
#include"parameterst.h"
#include<iostream>

OfficeT::OfficeT(sf::Vector2u window_size, sf::Vector2i end_size, std::string window_name,std::string office_path, std::string end_path, std::string end_sound_path, std::string door_path, std::string button_path, std::string camera_button_path, int end_amount, int doors_amount, int buttons_amount, std::vector<sf::Vector2f> Door_possition, std::vector<sf::Vector2f> Buttons_possition, sf::Vector2f camera_button_possition) : power_usage{1}, cam_button{camera_button_path,camera_button_possition,{1000,75}} //Constructor of OfficeT.
{
    window = new sf::RenderWindow; //We alocate memory to render window.
    window->create(sf::VideoMode(window_size), window_name); //We name window, and define its size.

    sf::Image icon;
    if(!icon.loadFromFile("../../img/icon.png"))
    {
        std::cerr << "Error! Failed to load icon!";
    }

    window->setIcon(icon);

    if(!end_buffer.loadFromFile(end_sound_path))
        std::cerr << "Error! Fail to load 6 am sound.";

    end_sound.setBuffer(end_buffer);

    for(int i=0;i<doors_amount;i++) //For value of argument we push to vector coresponding amount of doors.
    {
        if(i%2==0)
            Doors.push_back(DoorT {door_path, Door_possition[i], 5, {150,700}, true}); //We push back to vector.
        else
            Doors.push_back(DoorT {door_path, Door_possition[i], 5}); //We push back to vector.
    }

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
        std::cerr << "Error! Failed to load texture of office.\n";

    for(int i=0; i<3;i++)
    {
        Sprites_variants[i] = sf::IntRect{{i*static_cast<int>(window_size.x),0},{static_cast<int>(window_size.x),static_cast<int>(window_size.y)}};
    }

    sprite.setTexture(texture,true); //We set texture to office sprite (We gonna draw on screen this one.
    sprite.setTextureRect(Sprites_variants[0]);

    if(!end_texture.loadFromFile(end_path))
        std::cerr << "Error! Failed to load texture of 6 am\n";

    int i{},m{};
    while(m<end_amount)
    {
        for(int j=0;j<3;j++)
        {
            m++;

            End_variants.push_back({{end_size.x*j,end_size.y*i},{end_size.x,end_size.y}});
        }

        i++;
    }

    Nose_Hitbox.setSize({4,4});
    Nose_Hitbox.setPosition({633,402});
    Nose_Hitbox.setFillColor(sf::Color::Transparent);

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

void OfficeT::Clicked(ParametersT &x, std::vector<AnimatronT*> ani) //Function that check wich button (Or nose, was Clicked).
{
    window->setView(view); //We set view, to hitboxes was check right.
    sf::Vector2f MousePos{window->mapPixelToCoords(sf::Mouse::getPosition(*window))}; //We get mouse possition, from office screen (including view change).

    if(Nose_Hitbox.getGlobalBounds().contains(MousePos))
        nose_sound.play();

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

    if(x.phone.button.actual_variant && x.phone.Clicked(MousePos))
    {
        x.phone.PhoneCalls[x.Send_Night()].stop();
        if(x.phone.Skiped + x.phone.temp_Skiped >= 3 && x.phone.Skiped + x.phone.temp_Skiped < 5)
        {
            if(x.phone.Skiped + x.phone.temp_Skiped >= 4)
                x.phone.Stories[x.phone.Skiped + x.phone.temp_Skiped-4].stop();
            x.phone.Strikes[x.phone.Skiped + x.phone.temp_Skiped-3].play();
        }
        else if(x.phone.Skiped + x.phone.temp_Skiped == 5)
        {
            x.phone.Stories[x.phone.Skiped + x.phone.temp_Skiped-4].stop();
            x.phone.Strikes[x.phone.Skiped + x.phone.temp_Skiped-3].play();
            x.Hard_mode(ani);
        }
    }

    window->setView(window->getDefaultView()); //We return to default view. (Just in case.)
}

void OfficeT::Update_Door_texture()
{
    for(int i=0;i<2;i++)
        Doors[i].sprite.setTextureRect(Doors[i].Used_variants[Doors[i].Get_texure()]);
}

#define plaing sf::SoundSource::Status::Playing

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

    window->draw(Nose_Hitbox);

    window->setView(window->getDefaultView()); //We set back default view to draw interface.
    for(int i=0;i<2;i++)
        window->draw(Scroll_Hitbox[i]); //We draw each scroll hitbox.

    if(y.camera_window==nullptr && x.Send_Energy() > 0) //If camera is close:
        window->draw(cam_button.sprite); //We draw camera button.

    if(x.phone.PhoneCalls[x.Send_Night()].getStatus() == plaing || x.phone.Stories[ (x.phone.Skiped+x.phone.temp_Skiped >= 3 && x.phone.Skiped+x.phone.temp_Skiped < 5)? x.phone.Skiped+x.phone.temp_Skiped-3 : 0 ].getStatus() == plaing)
        window->draw(x.phone.button.sprite);

    if(x.phone.Skiped + x.phone.temp_Skiped >= 3 && x.phone.Skiped + x.phone.temp_Skiped < 5)
    {
        if(x.phone.Stories[x.phone.Skiped + x.phone.temp_Skiped-3].getStatus() == sf::SoundSource::Status::Stopped && x.phone.Strikes[x.phone.Skiped + x.phone.temp_Skiped-3].getStatus() == sf::SoundSource::Status::Stopped)
        {
            x.phone.Stories[x.phone.Skiped + x.phone.temp_Skiped-3].play();
            x.phone.button.Set_sprite_variant(1);
        }
    }


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

    Battery_txt.setString("Power: " + ((x.Send_Energy()>0)? std::to_string(x.Send_Energy()/7) : "0") + "%"); //We set string to Battery text. (We take value from parametersT.
    Battery_txt.setPosition({1000,10}); //We set possition of it.
    Battery_txt.setFillColor(sf::Color::Blue); //And color.

    Hour_txt.setString(std::to_string((x.Send_Hour())? x.Send_Hour() : 12) + " AM"); //We set string to Hour text. (We take value from parametersT.
    Hour_txt.setPosition({20,10}); //We set possition of it.
    Hour_txt.setFillColor(sf::Color::Blue); //And color.

    window->draw(Battery_txt); //Finaly we draw both texts on screen.
    window->draw(Hour_txt);
}

void OfficeT::Open()
{
    window = new sf::RenderWindow;
    window->create(sf::VideoMode({1200,1000}),"Office");

    sf::Image icon;
    if(!icon.loadFromFile("../../img/icon.png"))
    {
        std::cerr << "Error! Failed to load icon!";
    }

    window->setIcon(icon);
}

void OfficeT::Close()
{
    if(window != nullptr)
    {
        window->close();
        delete window;
        window = nullptr;
    }
}

void OfficeT::Load_Nose_Beep(std::string path)
{
    if(!nose_buffer.loadFromFile(path))
        std::cerr << "Error! Fail to load nose beep!\n";

    nose_sound.setBuffer(nose_buffer);
}


void OfficeT::Load_Jumpscare(std::string img_path, std::string audio_path, int jump_amnt, int ani_amnt, int anim_size)
{
    if(!jumpscare_texture.loadFromFile(img_path))
    {
        std::cerr << "Error! Fail to load jumpscare texture.\n";
    }

    if(!jumpscare_buffer.loadFromFile(audio_path))
    {
        std::cerr << "Error! Fail to load jumpscare audio!\n";
    }
    jumpscare_audio.setBuffer(jumpscare_buffer);

    int l{};
    for(int i=0;i<ani_amnt;i++)
    {
        std::vector<sf::IntRect> tmp{};

        for(int k=1;k<=anim_size;k++)
        {
            for(int j=0;j<jump_amnt;j++)
            {
                tmp.push_back(sf::IntRect{{1200*j,1000*l},{1200,1000}} );
            }
            l++;
        }
        Jumpscares_variants.push_back(tmp);
    }

    jumpscare_sprite.setTexture(jumpscare_texture, true);
    jumpscare_sprite.setTextureRect(Jumpscares_variants[0][0]);
}

void OfficeT::Jumpscare(jumpscare x, CamerasT &y, ParametersT &z)
{
    y.Close();

    std::vector<sf::IntRect> Jumpscaring = Jumpscares_variants[x.who];

    sf::Clock jumpscare_clock{};
    jumpscare_clock.start();
    jumpscare_audio.play();

    while(jumpscare_clock.getElapsedTime().asMilliseconds() < 2200)
    {
        int time = jumpscare_clock.getElapsedTime().asMilliseconds();

        window->clear();
        window->setView(view);

        window->draw(sprite);
        for(auto el : Door_Buttons)
            window->draw(el.sprite);
        for(auto el : Light_Buttons)
            window->draw(el.sprite);
        for(auto el : Doors)
            window->draw(el.sprite);

        window->setView(window->getDefaultView());
        jumpscare_sprite.setTextureRect(Jumpscaring[time/100]);
        window->draw(jumpscare_sprite);

        window->display();
    }

    Ending(3);
    Close();
}

void OfficeT::Load_Endings(std::string img_path, std::string audio_path, int endings_amnt)
{
    if(!ending_texture.loadFromFile(img_path))
    {
        std::cerr << "Error! Fail to load ending texture!\n";
    }

    for(int i=0;i<endings_amnt;i++)
    {
        Ending_variants.push_back({{i*1200,0},{1200,1000}});
    }

    if(!ending_buffer.loadFromFile(audio_path))
    {
        std::cerr << "Error! Fail to load ending audio!\n";
    }

    ending_audio.setBuffer(ending_buffer);
}

void OfficeT::Ending(int x)
{
    sprite.setTexture(ending_texture);
    sprite.setTextureRect(Ending_variants[x]);

    sf::Clock Ending_clock;
    Ending_clock.start();

    ending_audio.play();
    while(Ending_clock.getElapsedTime().asSeconds() < 5)
    {
        window->clear();

        window->draw(sprite);

        window->display();

        while(const std::optional event = window->pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                Close();
            }
        }
    }
}


void OfficeT::start_night(ParametersT& x)
{
    sf::Font comic_sans; //We define font.
    if(!comic_sans.openFromFile("../../img/fonts/Comic Sans MS.ttf")) //We open font from files.
    {
        std::cout << "Error! Fail to load font!\n";
    }

    sf::Text Night_title(comic_sans);
    if(x.Send_Custom())
    {
        Night_title.setString("CUSTOM NIGHT");
    }
    else
    {
        Night_title.setString("NIGHT " + std::to_string(x.Send_Night()+1));
    }
    Night_title.setPosition({592,500});
    Night_title.setFillColor(sf::Color::White);

    sprite.setTextureRect(Sprites_variants[1]);
    sf::Clock intro_clock;
    intro_clock.start();

    while(intro_clock.getElapsedTime().asSeconds() < 5)
    {
        window->clear();

        window->draw(sprite);
        window->draw(Night_title);

        window->display();
        while(const std::optional event = window->pollEvent()) //Hello
        {
            if(event->is<sf::Event::Closed>())
            {
                window->close();
                return;
            }
        }
    }

    sprite.setTextureRect(Sprites_variants[0]);
}

void OfficeT::end_night()
{
    sf::Sprite hour{end_texture};
    hour.setTextureRect(End_variants[0]);
    hour.setPosition({400,375});

    sprite.setTextureRect(Sprites_variants[1]);

    sf::Clock end_clock;
    end_sound.play();
    end_clock.start();

    while(end_clock.getElapsedTime().asSeconds() <= 12)
    {
        int x = end_clock.getElapsedTime().asSeconds();

        hour.setTextureRect(End_variants[x]);

        window->clear();

        window->draw(sprite);
        window->draw(hour);

        window->display();
        while(const std::optional event = window->pollEvent()) //Hello
        {}
    }

    end_clock.stop();
    sprite.setTextureRect(Sprites_variants[0]);
}

void OfficeT::Power_off()
{
    for(auto &el : Light_Buttons)
        el.Power_off();
    for(auto &el : Door_Buttons)
        el.Power_off();
}

OfficeT::~OfficeT()
{
    Close();
}
