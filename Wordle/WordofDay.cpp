#include"WordofDay.h"
#include "ReadWordsFromFlie.h"
#include "WriteGuessedWordtofile.h"
#include "compGuessedWordfromFile.h"
#include "AlgorithmCompareWords.h"

void DayDefinitions(const char* fileName, std::string& wordDay)
{
	std::fstream file;
	file.open(fileName, std::ios::in);

	if (!file)
	{
		std::cout << "File not found! Create file: date.log\n";
		writeDateToFile("date.log", "Create Date files");
		wordDay = "try";
	}
	else
	{
		const unsigned int MaxLineSize = 26;
		char line[MaxLineSize]{};
		while (!file.eof()) {

			file.getline(line, MaxLineSize, '\n');
			if (line[0] == '\0') {
				if (line[1] != '\0') {
					break;
				}
			}
			time_t currentTime;
			time(&currentTime);

			char timeNow[26];
			char switchDay[4];
			ctime_s(timeNow, sizeof(timeNow), &currentTime);

			for (int i = 0; i < sizeof(switchDay); i++) {
				switchDay[i] = timeNow[i];
			}
			switchDay[3] = '\0';
			for (int i = 0; i < 11; i++) {
				if (timeNow[i] != line[i]) {
					if (strcmp(switchDay, "Mon") == 0) {
						readWordfromFile("WordsMon.txt", wordDay);
						break;
					}
					else if (strcmp(switchDay, "Tue") == 0) {
						readWordfromFile("WordsTue.txt", wordDay);
						break;
					}
					else if (strcmp(switchDay, "Wed") == 0) {
						readWordfromFile("WordsWed.txt", wordDay);
						break;
					}
					else if (strcmp(switchDay, "Thu") == 0) {
						readWordfromFile("WordsThu.txt", wordDay);
						break;
					}
					else if (strcmp(switchDay, "Fri") == 0) {
						readWordfromFile("WordsFri.txt", wordDay);
						break;
					}
					else if (strcmp(switchDay, "Sat") == 0) {
						readWordfromFile("WordsSat.txt", wordDay);
						break;
					}
					else if (strcmp(switchDay, "Sun") == 0) {
						readWordfromFile("WordsSun.txt", wordDay);
						break;
					}
					else {
						std::cout << "Error! Compare date.log with current date\n";
					}
				}
			}

		}
	}
	file.close(); 
}
void WordDay()
{
	unsigned int tries = 0;
	time_t currentTime;
	time(&currentTime);

	char timeNow[26];
	ctime_s(timeNow, sizeof(timeNow), &currentTime);

	std::string wordDay = "-----";
	DayDefinitions("date.log", wordDay);
	std::srand(std::time(0));
	std::string guessedWord = "*****";
	if (wordDay == "-----") {
		std::cout << "Already found! Come back tomorrow!\n" << std::endl;
	}
	else if (wordDay == "try") {
		std::cout << "Please try again\n";
	}
	else {
		std::cout << "\tWord of Day Puzzle\n";
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
				CompareWord(wordDay, WordUser, guessedWord);
				tries++;
			}
		} while (wordDay != WordUser);
		std::cout << "Thats right! You made " << tries << " tries\n" << std::endl;
		writeFile("ListGuessedWord.txt", wordDay);
		writeDateToFile("date.log", timeNow);
	}
}