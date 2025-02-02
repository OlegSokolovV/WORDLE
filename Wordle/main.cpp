#include "ReadWordsFromFlie.h"
#include "WriteGuessedWordtofile.h"
#include "WordofDay.h"
#include "AlgorithmCompareWords.h"
#include "RandomWord.h"
#include <conio.h>



int main()
{
	unsigned int choice = 1;
	do {
		std::cout << "\n\tWORDLE PUZZLE\n\n";
		std::cout << "1 - Wordle of the day\n";
		std::cout << "2 - Random Wordle\n";
		std::cout << "0 - Exit\n";
		switch (_getch())
		{
		case 49:
			WordDay();
			break;
		case 50:
			RandomWord();
			break;
		case 48:
			choice = 0;
			break;
		default:
			std::cout << "Wrong number. try again\n";
			break;
		}

	} while (choice > 0);
	
	return 0;
}
