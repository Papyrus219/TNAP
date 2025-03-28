#ifndef TELEPHONET
#define TELEPHONET

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class TelephoneT
{
public:
	int Skiped{}; //My heart is broken, You don't answer my calls;
	std::vector<sf::Music> PhoneCalls{};
	std::vector<sf::Music> Strikes{};

	TelephoneT(std::string path, int numPhoneCalls, int numStrikes);
};

#endif



	
