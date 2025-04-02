#include "telephone.h"
#include <iostream>

TelephoneT::TelephoneT(std::string path, int numPhoneCalls, int numStrikes, std::string button_path, sf::Vector2f button_poss, std::pair<int,int> se): button(button_path, button_poss, se)
{
	for (int i = 0; i < numPhoneCalls; i++)
	{
		sf::Music &temp = PhoneCalls.emplace_back();
		if (!temp.openFromFile(path + "Night" + std::to_string(i + 1) + ".wav") )
		{
			std::cerr << "Audio Failed To Load";
		}
	}

	for (int i = 0; i < numStrikes; i++)
	{
		sf::Music &temp = PhoneCalls.emplace_back();
		if (!temp.openFromFile(path + "Strike_" + std::to_string(i + 1) + ".wav"))
		{
			std::cerr << "Audio Failed To Load";
		}
	}
}

bool TelephoneT::Clicked(sf::Vector2f x)
{
	if(button.Clicked(x))
	{
		Skiped++;
		return true;
	}

	return false;
}

