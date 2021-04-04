#include <iostream> // for general input / output
#include <fstream> // to read from file
#include <time.h> // for initialise rand
#include <vector> // to contain file input stream text, in this case the contents of words.txt 
#include <string> // standard string usage
#include <stdlib.h> // to select random word
#include "dialogue.h" // to centralise all in-game dialogue in one location
#include "log.h" // function for logging text to the console
#include "drawing.h" // function for drawing the stickman and gallows to 
#include "words.h" // string array of words to be used in the game
#include "gameFunctions.h" // functions to ask the player to guess and check the letter the player submitted




int main()
{
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
	 4) If player doesn't want to play again, end game
	 */

	// Welcome the player, ask if they want to play game, and receive player choice input
	char playGame;
	Log(welcomeText); 
	std::cin >> playGame; 


	// If player says yes, then proceed with game
	while (playGame == 'Y' || playGame == 'y')
	{
		srand(time(0));
		std::string secretWord;
		int wrongGuesses = 0;
		int totalLines = 0;
		bool gameOver = false;
		char playerGuess = 0;


		int random_number = rand() % (wordCount - 1); 
		secretWord = allWords[random_number];

		// Initalise hiddenWord with blanks
		std::string hiddenWord(secretWord.length(), '_');

		while (gameOver != true)
		{
			drawStickman(wrongGuesses);
			if (wrongGuesses == 6)
			{
				Log(youLoseText);
				Log(wordRevealText);
				Log(secretWord);
				gameOver = true;
				break;
			}
			if (hiddenWord == secretWord)
			{
				Log(youWinText);
				Log(wordRevealText);
				Log(secretWord);
				gameOver = true;
				break;
			}
			Log(questionText);
			guessing(hiddenWord, playerGuess);
			wordCheck(secretWord, playerGuess, hiddenWord, wrongGuesses);
			
		}
		Log(playAgainText);
		std::cin >> playGame;
		if (playGame == 'n' || playGame == 'N')
		{
			break;
		}
		
	}
	
}


