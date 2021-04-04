#include <iostream>
#include <string>
#include "dialogue.h" // to centralise all in-game dialogue in one location


void Log(const std::string message);

void drawStickman(int wrongGuesses)
{
	switch (wrongGuesses)
	{
	case 0:
		std::cout << "______" << "\n";
		std::cout << " |   |" << "\n";
		std::cout << "     |" << "\n";
		std::cout << "     |" << "\n";
		std::cout << "     |" << "\n";
		std::cout << "_____|" << "\n";
		break;
	case 1:
		std::cout << "______" << "\n";
		std::cout << " |   |" << "\n";
		std::cout << " O   |" << "\n";
		std::cout << "     |" << "\n";
		std::cout << "     |" << "\n";
		std::cout << "_____|" << "\n";
		break;
	case 2:
		std::cout << "______" << "\n";
		std::cout << " |   |" << "\n";
		std::cout << " O   |" << "\n";
		std::cout << " I   |" << "\n";
		std::cout << "     |" << "\n";
		std::cout << "_____|" << "\n";
		break;
	case 3:
		std::cout << "______" << "\n";
		std::cout << " |   |" << "\n";
		std::cout << " O   |" << "\n";
		std::cout << "/I   |" << "\n";
		std::cout << "     |" << "\n";
		std::cout << "_____|" << "\n";
		break;
	case 4:
		std::cout << "______" << "\n";
		std::cout << " |   |" << "\n";
		std::cout << " O   |" << "\n";
		std::cout << "/I\\  |" << "\n";
		std::cout << "     |" << "\n";
		std::cout << "_____|" << "\n";
		break;
	case 5:
		std::cout << "______" << "\n";
		std::cout << " |   |" << "\n";
		std::cout << " O   |" << "\n";
		std::cout << "/I\\  |" << "\n";
		std::cout << "/    |" << "\n";
		std::cout << "_____|" << "\n";
		break;
	case 6:
		std::cout << "______" << "\n";
		std::cout << " |   |" << "\n";
		std::cout << " O   |" << "\n";
		std::cout << "/I\\  |" << "\n";
		std::cout << "/ \\  |" << "\n";
		std::cout << "_____|" << "\n";
		break;
	}
}
