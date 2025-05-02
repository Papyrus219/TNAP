#include "telephone.h"
#include <iostream>

TelephoneT::TelephoneT(std::string path, int numPhoneCalls, int numStrikes, int numStories, std::string button_path, sf::Vector2f button_poss, std::pair<int,int> se): button(button_path, button_poss, se)
{
	for (int i = 0; i < numPhoneCalls; i++)
	{
		sf::Music &temp = PhoneCalls.emplace_back();

		srand(time(NULL));
		if(!(rand()%100))
		{
			if(!temp.openFromFile("../../audio/phoneguy/Litwa.wav"))
			{
				std::cerr << "Easter egg canceled!\n";

				if (!temp.openFromFile(path + "Night" + std::to_string(i + 1) + ".wav") )
				{
					std::cerr << "Audio Failed To Load";
				}
			}
		}
		else
		{
			if (!temp.openFromFile(path + "Night" + std::to_string(i + 1) + ".wav") )
			{
				std::cerr << "Audio Failed To Load";
			}
		}
	}

	for (int i = 0; i < numStrikes; i++)
	{
		sf::Music &temp = Strikes.emplace_back();
		if (!temp.openFromFile(path + "Strike_" + std::to_string(i + 1) + ".wav"))
		{
			std::cerr << "Audio Failed To Load";
		}
	}

	for(int i = 0; i < numStories; i++)
	{
		sf::Music &temp = Stories.emplace_back();
		if(!temp.openFromFile(path + "Story" + std::to_string(i+1)+ ".wav"))
		{
			std::cerr << "Audio Failed To Load";
		}
	}
}

bool TelephoneT::Clicked(sf::Vector2f x)
{
	if(button.Clicked(x))
	{
		temp_Skiped++;
		std::cerr << "Skiped! " << Skiped << " " << temp_Skiped << "\n";
		return true;
	}

	return false;
}

