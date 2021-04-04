#include <iostream> // for general input / output
#include "log.h"
#include "dialogue.h"
#include "gameFunctions.h" // functions to ask the player to guess and check the letter the player submitted


void guessing(std::string hiddenWord, char& playerGuess)
{
	std::cout << hiddenWord << "\n";
	std::cin >> playerGuess;
}

void wordCheck(std::string secretWord, char playerGuess, std::string& hiddenWord, int& wrongGuesses)
{
	//function to check if playerGuess is in secretWord
	if (secretWord.find(playerGuess) != std::string::npos)
	{
		Log(correctGuessText);
		for (unsigned int i = 0; i < secretWord.length(); ++i)
		{
			if (secretWord[i] == playerGuess)
			{
				hiddenWord[i] = playerGuess;
			}
		}
	}
	else
	{
		Log(wrongGuessText);
		wrongGuesses++;
	}
}