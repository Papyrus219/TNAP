#include "menut.h"
#include "buttons/menu_buttont.h"
#include  <fstream>

#include"custom_night_menut.h"
#include "officet.h"
#include "camerast.h"
#include "animatrons/animatront.h"
#include "animatrons/papyrus.h"
#include "animatrons/light.h"
#include "animatrons/bot.h"
#include "animatrons/brush.h"
#include "animatrons/mememan.h"
#include "parameterst.h"

MenuT::MenuT(std::string menu_path, std::string button_path, std::string star_path, std::string background_path, std::string intro_path, std::string audio_path, int options_amount, std::vector<sf::Vector2f> pos, std::pair<int,int> se, std::string skip_button_path, sf::Vector2f skip_button_possition, std::pair<int,int> skip_button_se): par{background_path, intro_path,20,0,"../../audio/phoneguy/",3,3,2, skip_button_path, skip_button_possition, skip_button_se}
{
    if(!background_music.openFromFile(audio_path))
    {
        std::cerr << "Error! Failed to load menu music!\n";
    }

    if(!texture.loadFromFile(menu_path))
        std::cerr << "Error! Failed to load menu texture.";

    sprite.setTexture(texture, true);
    sprite.setTextureRect(sf::IntRect{{0,0},{1200,1000}});

    for(int i=0;i<options_amount;i++)
        butions.push_back(Menu_ButtonT{button_path + std::to_string(i) + ".png", {pos[i].x,pos[i].y},{se.first,se.second}});

    if(!star_texture.loadFromFile(star_path))
    {
        std::cerr << "Error! Failed to load star texture.\n";
    }
    star_sprite.setTexture(star_texture,true);
}


void MenuT::open()
{
    background_music.play();
    background_music.setLooping(true);

    window = new sf::RenderWindow{};
    window->create(sf::VideoMode({1200,1000}),"Menu");

    sf::Image icon;
    if(!icon.loadFromFile("../../img/icon.png"))
    {
        std::cerr << "Error! Failed to load icon!";
    }

    window->setIcon(icon);


    if(par.actual_night< 3)
        par.phone.PhoneCalls[par.actual_night].stop();

    par.background.stop();
}

void MenuT::Render()
{
    if(window != nullptr)
    {
        window->clear();

        window->draw(sprite);
        for(int i=0;i<butions.size();i++)
            if(i !=2 || par.stars[0] == true)
                window->draw(butions[i].sprite);

        for(int i=0;i<par.stars_amount;i++)
        {
            star_sprite.setPosition({static_cast<float>(i*218),793});
            window->draw(star_sprite);
        }

        window->display();
    }
}

void MenuT::Click(Custom_night_menuT &x)
{
    sf::Vector2f MousePos{sf::Mouse::getPosition(*window)};

    for(int i=0;i<butions.size();i++)
    {
        if(butions[i].sprite.getGlobalBounds().contains(MousePos))
        {
            switch(i)
            {
                case 0:
                    Newgame();
                    break;
                case 1:
                    Continue();
                    break;
                case 2:
                    if(par.stars_amount > 0)
                        Custom_night(x);
                    break;
                case 3:
                    Exit();
                    break;
            }
            return;
        }
    }
}

void MenuT::gameplay(std::vector<int> custom_dif)
{
    background_music.pause();

    AnimatronT::Possitions = {0,0,0,0,0,0,0,0,0,0,0};

    Papyrus pap{"../../audio/animatrons/papyrus.wav", -1, 5, {0,1,2,7,9}};
    Light light{"../../audio/animatrons/light.wav", -1, 7, {0,5,8,6,8,10}};
    Brush brush{"../../audio/animatrons/brush.wav", -1, 6, {0,5,8,10,9}};
    Bot bot{"../../audio/animatrons/bot.wav", -1, 6, {0,1,2,3,4,5}};
    Mememan meme{"../../audio/animatrons/meme.wav", "../../img/cameras/meme_man_button.png", {750,510}, {300,150}, -1, 2, {0}};

    std::vector<AnimatronT*> ani{&pap, &meme, &light, &bot, &brush};

        OfficeT office{{1200,1000}, {400,250}, "TNAP", "../../img/office/office.png", "../../img/office/6am.png", "../../audio/6am.wav", "../../img/door/door.png", "../../img/button/button.png", "../../img/button/camera.png", 12, 2, 2, {{175,350}, {1020,340}}, {{200,400}, {960,400}}, {100,875}}; //We define object of OfficeT.
        office.Load_Jumpscare("../../img/office/Jumpscares.png","../../audio/animatrons/jumpscare.wav",5,5);
        office.Load_Endings("../../img/office/endings.png","../../audio/ending.wav",4);
        office.Load_Nose_Beep("../../audio/animatrons/nose.wav");

        CamerasT cameras{"../../img/cameras/cameras.png", "../../img/cameras/camera_panel.png",{1000,667}, {47,33}, 11, 35, {8,2,2,5,2,2,2,2,2,4,4}, {{99,30},{59,71},{139,70},{28,135},{14,28},
        {233,33},{193,141},{104,170},{250,138},{114,250},{233,251}}}; //We define object of CamerasT.

        par.New_Night(ani,office,custom_dif);
        std::cerr <<par.Send_Night() << '\n';

        while(office.window->isOpen())
        {
            office.Scroll(); //We check if player cursor is in ,,scroll zone".

            if(cameras.camera_window==nullptr && par.Send_Energy() > 0)
                if(office.Camera_Open(cameras)) //We check if player open camera.
                    office.Update_Energy_Usage(3);

            while(const std::optional event = office.window->pollEvent()) //Hello
            {
                office.Scroll(); //We check if player cursor is in ,,scroll zone".

                if (event->is<sf::Event::Closed>()) //Standard, we check if window is closed.
                {
                    office.Close();
                    cameras.Close();
                    office.Update_Energy_Usage(-3); //We update energy ussage.
                    return;
                }
                else if(event->is<sf::Event::MouseButtonPressed>()) //We check if window was clicked and then...
                {
                    if(par.Send_Energy()>0)
                        office.Clicked(par,ani); //...we start function wich check all elements that can be clicked.
                }
            }

            office.Render(par,cameras); //We render everything in office.

            if(cameras.camera_window != nullptr) //If camera window exist.
            {
                cameras.Render(meme); //We render everything in cameras.

                while(const std::optional event = cameras.camera_window->pollEvent()) //If any event in camera window detected:
                {
                    if(event->is<sf::Event::Closed>()) //We check if player close window.
                    {
                        cameras.Close(); //If yes, we need to run function that free memory, and clean up.
                        office.Update_Energy_Usage(-3);
                        break;
                    }
                    else if(event->is<sf::Event::MouseButtonPressed>()) //If button presed:
                    {
                        cameras.Camera_change(meme); //If yes, we run function which check if player.
                    }
                }
            }

            par.Update_Power_Ussage({office.Get_power_usage()});
            if(int x=par.Tic(*this,office,cameras,ani)) //And check if tic happen.
            {
                if(x==-2)
                {
                    return;
                }

                office.Update_actual_camera(cameras);

                try
                {
                for(auto el : ani)
                    cameras.Animatron_Move(el->Move(office));
                }
                catch(jumpscare x)
                {
                    office.Jumpscare(x,cameras,par);
                    return;
                }
            }
        }
}

void MenuT::Newgame()
{
    std::ofstream save_file{"../../data/save.txt", std::ios::trunc};

    par.actual_night = 0;
    par.phone.Skiped = 0;

    save_file << par.actual_night << ';' << par.stars_amount << ';';

    for(int i=0;i<3;i++)
        save_file << ((par.stars[i])? '1' : '0' ) << ';';

    save_file << '~';

    save_file.close();

    sprite.setTextureRect(sf::IntRect{{1200,0},{1200,1000}});

    sf::Clock intro_clock;
    intro_clock.start();

    while(intro_clock.getElapsedTime().asSeconds() < 5)
    {
        window->clear();
        window->draw(sprite);
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

    sprite.setTextureRect(sf::IntRect{{0,0},{1200,1000}});
    close();
    gameplay();
    par.tic_clock.reset();
    par.time_clock.reset();
    open();
}

void MenuT::Continue()
{
    std::ifstream save_file{"../../data/save.txt"};

    if(!save_file.is_open())
        Newgame();

    std::string t{};
    int mode = 0;

    std::getline(save_file,t);
    for(int i=0;i<t.size();i++)
    {
        if(t[i] == ';' || t[i] == '~')
        {
            mode++;
        }
        else
        {
            switch(mode)
            {
                case 0:
                {
                    par.actual_night = t[i]-48;
                    break;
                }
                case 1:
                {
                    int amout = t[i]-48;
                    for(int i=0;i<amout;i++)
                        par.stars[i] = true;
                    par.stars_amount = amout;
                    break;
                }
                default:
                {
                    if(t[i]-48)
                        par.stars[mode-2] = true;
                    else
                        par.stars[mode-2] = false;
                }

            }
        }
    }

    if(par.actual_night > 2)
    {
        par.actual_night = 2;
        if(par.phone.Skiped > 3)
            par.phone.Skiped = 3;
    }

    window->close();
    gameplay();
    par.tic_clock.reset();
    par.time_clock.reset();
    open();
}

void MenuT::Custom_night(Custom_night_menuT &x)
{
    par.tic_clock.reset();
    par.time_clock.reset();
    x.open();
}

void MenuT::Exit()
{
    close();
}


void MenuT::close()
{
    background_music.stop();

    if(window != nullptr)
        window->close();
    delete window;
    window = nullptr;
}

MenuT::~MenuT()
{
    delete window;
    window = nullptr;
}
