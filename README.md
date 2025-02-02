This game is designed to guess a word of 5 letters.
It consists of two options:
1. Word of the day (can be played once a day)
2. Random words

The algorithm of the game is very simple:
- checking the size of the word by the player being played (if less than 5, asks the player to play again. And if more, cuts it to 5).
- checking the correct characters, if the played characters are not English a-z, A-Z.
- checking the repeating characters to 4. If 5 are played, asks to play the word again.
- matching characters in words.

In the "Word of the day" mode, before starting, it checks today's date and compares it with the date saved in the date.log file (if the file does not exist, a new one is created).
Example of comparison: “Sun Feb 2 17:35:43 2025” which is in the date.log file and with the current date at start. (The comparison goes to "Sun Feb 2". And if the player will run it once a week, or several times per game).
The word selection follows this algorithm:
- It is determined what day, takes the desired file.
- It is determined how many words in the file, generates a number and selects it from the list.
- It is checked whether this word is guessed with the list in the file ListGuessedWord.txt, if YES, then the number is generated again and checked.
After guessing the word, the word is added to the list, which is stored in the file ListGuessedWord.txt.

In the "Random Words" mode, the same thing but without restrictions on the date and file selection. All words are randomly selected from the list in the file random_words.txt. It is compared with the list of guessed words in the file ListGuessedWord.txt. After guessing, the word is added to the list ListGuessedWord.txt.

In this game, I added colored letters as a result, instead of an asterisk, a dark gray letter.
There was a problem when in the main.ccp file in the switch() menu after 1 or 2 and pressing Enter, it worked that I had already typed a word, it passes the check and writes less than 5 characters. Therefore, I added data entry without enter))) _getch().

In the future, it is necessary to:
1. optimize the date comparison algorithm. It seems to me so.
2. action after the end of words. Either clearing the list of guessed words, or adding new words.
3. Optimize the number of files.

Below I add a list of files:

AlgorithmCompareWords.h
AlgorithmCompareWords.cpp
- bool checkSyntaxWord(std::string word); // check for repetition and correct characters
- void CompareWord(std::string hiddenWord, std::string userWord, std::string result);// compare words and output the result

compGuessedWordfromFile.h
compGuessedWordfromFile.cpp
- bool compasionGuessedWord(const char* fileName, const char* word); // compare a random word from the file with the list of guessed words ListGuessedWord.txt. (returns 0 if it matches.
main.cpp // there is the main() function and the game menu
RandomWord.h // Random Words Mode
RandomWord.cpp // Random Words Mode
ReadWordsFromFlie.h
ReadWordsFromFile.cpp // the number of words in the list from the file is checked, and a number is generated, then the function compasionGuessedWord("ListGuessedWord.txt", line) checks the word, if the word matches, a new random word is generated again.
WordofDay.h
WordofDay.cpp // Word of the Day Mode
WriteGuessedWordtofile.h
WriteGuessedWordtofile.cpp // adding a word to the ListGuessedWord.txt list
date.log // the date of the game in Word of the Day mode is stored, for checking
ListGuessedWord.txt // list of guessed words
random_words.txt // list words for Random Words mode
WordsMon.txt // list of words for the current day Mon-Sun
WordsTue.txt
WordsWed.txt
WordsThu.txt
WordsFri.txt
WordsSat.txt
WordsSun.txt