#include <string>
#include <iostream>
#include "dialogue.h"

//I wanted to have all dialogue / text options in the game to be in one place for easier access. Made extern and const

extern const std::string welcomeText = "Hello! Would you like to play a game of hangman? Y/N";
extern const std::string questionText = "Guess a letter";
extern const std::string correctGuessText = "You guessed correctly!";
extern const std::string wrongGuessText = "You chose poorly!";
extern const std::string youWinText = "Congratulations! You won!";
extern const std::string youLoseText = "Oh No! You lost!";
extern const std::string playAgainText = "Would you like to play again? Y/N";
extern const std::string wordRevealText = "The word was: ";