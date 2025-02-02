#pragma once
#include "ReadWordsFromFlie.h"
#include "WriteGuessedWordtofile.h"
#include "WordofDay.h"
#include <cctype>
#include<string>
#include <algorithm>
#include <Windows.h>

bool checkSyntaxWord(std::string word);
void CompareWord(std::string hiddenWord, std::string userWord, std::string result);
