#include "telephone.h"
#include <iostream>

TelephoneT::TelephoneT(std::string path, int numPhoneCalls, int numStrikes)
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
