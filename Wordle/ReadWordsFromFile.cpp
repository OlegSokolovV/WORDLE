#include "ReadWordsFromFlie.h"
#include "compGuessedWordfromFile.h"

void readWordfromFile(const char* fileName, std::string& word)
{
	std::fstream file;
	file.open(fileName, std::ios::in);

	if (!file)
	{
		std::cout << "File not found!\n";
	}
	else
	{
		std::srand(std::time(0));
		const unsigned int MaxLineSize = 6;
		char line[MaxLineSize]{};
		int NumberWords = 0;
		int count = 1;
		while (!file.eof())
		{
			const char ch = file.get();
			if (ch == '\n') {
				NumberWords++;
			}
		}
		NumberWords += 2;
		int randomValue = std::rand() % NumberWords;
		file.clear();
		file.seekg(0, std::ios::beg);
		while (!file.eof()) {
			
			file.getline(line, MaxLineSize, '\n');
			if (count == randomValue) {
				if (compasionGuessedWord("ListGuessedWord.txt", line)) {
					word = line;
					word[0] = std::tolower(word[0]);
					break;
				}
				else {
					std::cout << "Search new word...\n";
					randomValue = std::rand() % NumberWords;
					count = 0;
					file.clear();
					file.seekg(0, std::ios::beg);
				}
			}
			count++;
		}
	}

	file.close();
}