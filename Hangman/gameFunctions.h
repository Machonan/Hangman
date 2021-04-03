#pragma once

void guessing(std::string hiddenWord, char& playerGuess);
void wordCheck(std::string secretWord, char playerGuess, std::string& hiddenWord, int& wrongGuesses);