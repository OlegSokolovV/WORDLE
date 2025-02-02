#include "WriteGuessedWordtofile.h"

void writeFile(const char* fileName, std::string word)
{
	std::fstream file;
	file.open(fileName, std::ios::app);


	if (!file)
	{
		std::cout << "File not created!\n";
	}
	else
	{
		file << word;
		file << "\n";
		file.close();
	}

}
void writeDateToFile(const char* fileName, std::string word)
{
	std::fstream file;
	file.open(fileName, std::ios::out | std::ios::trunc);


	if (!file)
	{
		std::cout << "File not created!\n";
	}
	else
	{
		file << word;
		file.close();
	}
}