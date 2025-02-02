#include "AlgorithmCompareWords.h"

void setConsoleColor(int color) { // color text
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole, color);
}

bool checkSyntaxWord(std::string word)
{
	// Check repeat characters
	unsigned int countRepeat = 0;
	for (int i = 1; i < word.size(); i++) {
		if (word[0] == word[i]) countRepeat++;
	}
	if (countRepeat >= 4) { std::cout << "More repeated characters\n"; 
		return false; 
	}

	// Check correct characters a-z A-Z
	for (int i = 0; i < word.size(); i++) {
		if (word[i] >= 65 && word[i]<=90 || word[i]>=97 && word[i]<=122) {
			continue;
		}
		else {
			std::cout << "Wrong Character. Please enter correct character (a-z, A-Z)\n";
			return false;
		}
	}
	return true;
}

void CompareWord(std::string hiddenWord, std::string userWord, std::string result)
{
	if (hiddenWord == userWord) {
		for (int i = 0; i < hiddenWord.size(); i++) {
			result[i] = std::toupper(hiddenWord.at(i));
		}
	}
	else {
		for (int i = 0; i < hiddenWord.size(); i++) {
			for (int j = 0; j < userWord.size(); j++) {
				if (hiddenWord.at(i) == userWord.at(j)) {
					result.at(j) = userWord.at(j);
				}
			}
		}
		for (int i = 0; i < hiddenWord.size(); i++) {
			if (hiddenWord[i] == userWord[i]) {
				result.at(i) = std::toupper(userWord.at(i));
			}
		}
	}
	std::cout << "RESULT ";
	for (int i = 0; i < result.size(); i++) {
		if (result[i] == 42) {
			setConsoleColor(8);
			std::cout << userWord[i];
			setConsoleColor(7);
		}
		else if (result[i] < 97 && result[i] > 64){
			setConsoleColor(2);
			std::cout << result[i];
			setConsoleColor(7);
		}
		else {
			setConsoleColor(5);
			std::cout << result[i];
			setConsoleColor(7);
		}		
	}
	std::cout << std::endl;
}