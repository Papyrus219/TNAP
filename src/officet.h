#ifndef OFFICET_H
#define OFFICET_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"doort.h"
#include"buttons/light_buttont.h"
#include"buttons/door_buttont.h"
#include"buttons/camera_buttont.h"
#include"camerast.h"
#include"jumpscare.h"

/*
 * This class is managment for main window of game. Its open it, storage,
 * Its also have all obejcts of things that are render in window.
 */

class ParametersT;
class AnimatronT;

class OfficeT
{
public:
    OfficeT(sf::Vector2u window_size, sf::Vector2i end_size, std::string window_name,std::string office_path, std::string end_path, std::string end_soud_path, std::string door_path, std::string button_path, std::string camera_button_path, int end_amount ,int doors_amount, int buttons_amount , std::vector<sf::Vector2f> Door_possition, std::vector<sf::Vector2f> Buttons_possition, sf::Vector2f camera_button_possition); //Constructor.
    OfficeT(OfficeT &); //Copy constructor

    sf::RenderWindow* window; //Office window.
    int actual_camera_on{};

    void Open();
    void Close();
    void Show_Tittle_Board(); //To show on begining of each night.
    void Clicked(ParametersT &x, std::vector<AnimatronT*> ani); //When screen is clicked we will check some options.
    void Scroll(); //Function that check if cursor is in scroll area.
    void Change_office_texuture(int x)
    {sprite.setTextureRect(Sprites_variants[x]);}
    void Update_Energy_Usage(int x)
    {power_usage += x;}
    void Update_Door_texture();
    bool Camera_Open(CamerasT &x);
    bool Door_light_check(int which)
    {return Doors[which].Get_if_Light();}
    bool Door_status_check(int which) //When animatron ask if door is open.
    {return Doors[which].Get_if_close();}
    int Get_power_usage()
    {return power_usage;}
    void Update_actual_camera(CamerasT x)
    {actual_camera_on = x.act_camera;};
    void Render(ParametersT &x,CamerasT &y); //To show all office on screen.
    void Render_Stats(ParametersT &x); //Render Statistic on screen.
    void Change_Door_Textures(int x, int y, int a)
    {Doors[a].Used_variants[x] = Doors[a].Sprites_variants[y];}
    void Power_off();
    void start_night(ParametersT &x);
    void end_night();
    void Load_Jumpscare(std::string img_path, std::string audio_path, int jump_amnt, int ani_amnt);
    void Jumpscare(jumpscare x, CamerasT &y, ParametersT &z);
    void Load_Endings(std::string img_path, std::string audio_path, int endings_amnt);
    void Ending(int x);
    void Load_Nose_Beep(std::string path);

    ~OfficeT(); //Destructor.

private:
    std::vector<DoorT> Doors{}; //Vector of doors.
    std::vector<Door_ButtonT> Door_Buttons{}; //Vector of buttons.
    std::vector<Light_ButtonT> Light_Buttons{}; //Vector of buttons.
    sf::RectangleShape Scroll_Hitbox[2]; //Hitbox of scroll area.
    sf::RectangleShape Nose_Hitbox;
    bool Door_close_status[2]{}; //Status of if doors are closed.
    bool Door_light_status[2]{}; //Status of if doors are lighted.
    int Door_texture_status[2]{};
    int power_usage; //Actual power_usage of office.
    sf::Texture texture; //Texture of office.
    sf::Texture end_texture;
    sf::Texture jumpscare_texture;
    sf::Texture ending_texture;
    std::vector<sf::IntRect> End_variants{};
    std::vector<sf::IntRect> Ending_variants{};
    sf::IntRect Sprites_variants[3];
    sf::View view; //View. (For scroll effect.
    sf::Sprite sprite{texture}; //Sprite. This is what we will show on screen.
    sf::Sprite jumpscare_sprite{jumpscare_texture};
    int jumpscare_amount{};
    int frames_amount{};
    std::vector<std::vector<sf::IntRect>> Jumpscares_variants{};
    Camera_ButtonT cam_button; //Button to open camera.

    sf::SoundBuffer jumpscare_buffer;
    sf::Sound jumpscare_audio{jumpscare_buffer};
    sf::SoundBuffer end_buffer;
    sf::Sound end_sound{end_buffer};
    sf::SoundBuffer ending_buffer{};
    sf::Sound ending_audio{ending_buffer};
    sf::SoundBuffer nose_buffer;
    sf::Sound nose_sound{nose_buffer};

    //friend class ParametersT;
};

#endif // OFFICET_H
