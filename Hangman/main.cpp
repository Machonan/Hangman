#include <iostream> // for general input / output
#include <fstream> // to read from file
#include <time.h> // for initialise rand
#include <vector> // to contain file input stream text, in this case the contents of words.txt 
#include <string> // standard string usage
#include <stdlib.h> // to select random word
#include "dialogue.h" // to centralise all in-game dialogue in one location


void Log(const std::string message); // simple function for displaying dialogue
void drawStickman(int wrongGuesses); // function for drawing the stickman etc. 
void drawingSetup(int wrongGuesses);
void guessing(std::string hiddenWord, char& playerGuess);
void wordCheck(std::string secretWord, char playerGuess, std::string& hiddenWord, int& wrongGuesses);

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
	 4) End game loop
	 */

	char playGame = 0;
	
	
	// Welcome the player, ask if they want to play game, and receive player choice input
	Log(welcomeText); 
	std::cin >> playGame; 


	// If player says yes, then proceed with game
	while (playGame == 'Y' || playGame == 'y')
	{
		srand(time(0));
		std::string word;
		std::vector<std::string> allWords;
		std::string secretWord;
		std::ifstream file("words.txt");
		int wrongGuesses = 0;
		int totalLines = 0;
		char playerGuess = 'a';
		bool gameOver = false;

		// Read all words from file, add to number of total lines, and add to vector 
		while (getline(file, word))
		{
			totalLines++;
			allWords.push_back(word);
		}

		// Select a random line (word) from the vector
		int random_number = rand() % totalLines;
		secretWord = allWords[random_number];

		// Draw the current stickman (including gallows). Stickman drawing progress is based on number of wrong guesses		
		drawingSetup(wrongGuesses);


		// As this is the first round, only blanks will be shown 
		std::string hiddenWord(secretWord.length(), '_');

		while (gameOver != true)
		{
			guessing(hiddenWord, playerGuess);
			wordCheck(secretWord, playerGuess, hiddenWord, wrongGuesses);
			drawingSetup(wrongGuesses);
			if (wrongGuesses == 6)
			{
				Log(youLoseText);
				gameOver = true;
			}
			if (hiddenWord == secretWord)
			{
				Log(youWinText);
				gameOver = true;
			}

		}
		
	}
	std::cin.get();
}


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