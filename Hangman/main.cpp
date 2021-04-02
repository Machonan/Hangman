#include <iostream>
#include "log.h"
#include <fstream>
#include <time.h>
#include <vector>
#include <string>
#include<stdlib.h>


int main()
{
	//std::cout << "test" << "\n";
	/*Hangman Game
	* 1) Ask player if they want to play hangman
	* 2) If yes, start game. If no, end program
	* 3) Start game loop
	*    - Select word from dictionary file
	*	 - Present player with number of spaces (underscores) and ask them to guess a letter in the word.
	*    - Take input from player for one letter
	*    - If letter is in word, provide feedback and replace blank space with letter or letters
	*    - If letter is not in word, provide feedback and add to the hangman drawing
	*    - If player has 6 wrong guesses, game ends and player loses. GAME OVER message appears.
	     - If player gets word in < 6 guesses, player wins. CONGRATULATIONS message appears. 
	 4) End game loop

	*/

	char playGame;
	std::string word;
	std::vector<std::string> allWords;
	Log("Hello! Would you like to play a game of hangman? Y/N");
	std::cin >> playGame;

	while (playGame == 'Y' || playGame == 'y')
	{
		srand(time(0));
		/*Log("Hello! Would you like to play a game of hangman? Y/N");
		std::cin >> playGame;*/

		std::ifstream file("words.txt");

		int total_lines = 0;

		while (getline(file, word))
		{
			total_lines++;
			allWords.push_back(word);
		}

		int random_number = rand() % total_lines;

		std::cout << allWords[random_number];

		break;
	}


}