#include "RandomWord.h"


void RandomWord()
{
	unsigned int tries = 0;
	std::string guessedWord = { "*****" };
	std::string hiddenWord =  { "*****" };
	readWordfromFile("random_words.txt", hiddenWord);
	if (hiddenWord == "*****") {
		std::cout << "Error! Getting data from file!\nSystem try again operation...\n" << std::endl;
		readWordfromFile("random_words.txt", hiddenWord);
	}
	else {
		std::cout << "\tRandom Word Puzzle\n";
	}
	std::cout << guessedWord << std::endl;
	std::string WordUser;

	do {
		std::cout << "ENTER  ";
		getline(std::cin, WordUser);
		if (WordUser.size() > 5) {
			std::cout << "Attention! The word is longer than 5 characters.\n It will be shortened to 5 characters.\n";
			WordUser = WordUser.substr(0, 5);
		}
		else if (WordUser.size() < 5) {
			std::cout << "The word has less than 5 characters.\nPlease try again.\n";
			continue;
		}
		if (checkSyntaxWord(WordUser)) {
			CompareWord(hiddenWord, WordUser, guessedWord);
			tries++;
		}
	} while (hiddenWord != WordUser);
	std::cout << "Thats right! You made " << tries << " tries\n" << std::endl;
	writeFile("ListGuessedWord.txt",WordUser);
}