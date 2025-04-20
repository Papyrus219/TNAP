#ifndef TELEPHONET
#define TELEPHONET

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "buttons/skip_buttont.h"

class TelephoneT
{
public:
	int Skiped{}; //My heart is broken, You don't answer my calls;
	int temp_Skiped{};
	std::vector<sf::Music> PhoneCalls{};
	std::vector<sf::Music> Strikes{};
	std::vector<sf::Music> Stories{};
	Skip_ButtonT button{};
	bool Clicked(sf::Vector2f x);

	TelephoneT(std::string path, int numPhoneCalls, int numStrikes, int numStories, std::string button_path, sf::Vector2f button_poss, std::pair<int,int> se);
	TelephoneT() = default;
	TelephoneT(const TelephoneT&) = delete;

	~TelephoneT() = default;
};

#endif



	
