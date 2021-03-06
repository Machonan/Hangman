#include <string>
#include <iostream>
#include "dialogue.h"

//I wanted to have all dialogue / text options in the game to be in one place for easier access. Made extern and const

const std::string welcomeText = "Hello! Would you like to play a game of hangman? Y/N";
const std::string questionText = "Guess a letter";
const std::string correctGuessText = "You guessed correctly!";
const std::string wrongGuessText = "You chose poorly!";
const std::string youWinText = "Congratulations! You won!";
const std::string youLoseText = "Oh No! You lost!";
const std::string playAgainText = "Would you like to play again? Y/N";
const std::string wordRevealText = "The word was: ";