#include "compGuessedWordfromFile.h"
bool compasionGuessedWord(const char* fileName, const char* word)
{
	std::fstream file;
	file.open(fileName, std::ios::in);

	if (!file)
	{
		std::cout << "File not found!\n";
	}
	else
	{
		//By Line
		const unsigned int MaxLineSize = 6;
		char line[MaxLineSize]{};
		std::string Word = word;

		file >> std::noskipws;
		while (!file.eof())
		{
			file.getline(line, MaxLineSize, '\n');
			if (line == Word) {
				return false;
			}
		}
		return true;
	}
	file.close();
}