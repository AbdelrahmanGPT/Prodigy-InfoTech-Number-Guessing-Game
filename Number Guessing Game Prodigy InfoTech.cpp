#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include<string>
#include<array>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<limits>
#include<vector>
#include<fstream>
#include"ABODAstd.h"

using namespace std;

struct GameSettings {
	unsigned long long StartingNumber;
	unsigned long long EndingNumber;
	unsigned long long RandomNumber;
	unsigned short GuessingCounter;
};

bool IsGuessCorrect(unsigned long long GuessedNumber, unsigned long long RandomNumber, short& GuessingCounter)
{

	if (GuessedNumber > RandomNumber)
	{
		system("color 4F");
		printf("TOO HIGH :-( , THE NUMBER IS SMALLER THAN %d\n", GuessedNumber);
		GuessingCounter++;
		return 0;
	}

	else if (GuessedNumber < RandomNumber)
	{
		system("color 4F");
		printf("TOO LOW :-( , THE NUMBER IS BIGGER THAN %d\n", GuessedNumber);
		GuessingCounter++;
		return 0;
	}

	else
	{
		system("color 2F");
		printf("CONGRATULATIONS , YOU HAVE GUESSED THE NUMBER CORRECTLY :-)\n");
		printf("YOU TOOK %d ATTEMPT(S) TO GUESS THE NUMBER CORRECTLY\n" , ++GuessingCounter);
		return 1;
	}
}

void ReadGuessedNumberAndCheckTheGuess(unsigned long long RandomNumber, short GuessingCounter)
{
	unsigned long long GuessedNumber;

	do
	{

		GuessedNumber = ReadPositiveNumber("\nENTER NUMBER YOU WANT TO GUESS ?");

	} while (!IsGuessCorrect(GuessedNumber, RandomNumber, GuessingCounter));
}

unsigned long long ReadEndingNumber(unsigned long long StartingNumber)
{
	unsigned long long EndingNumber;
	do
	{
		EndingNumber = ReadPositiveNumber("ENTER ENDING NUMBER");

		if (EndingNumber < StartingNumber)
		{
			printf("WRONG NUMBER , ENDING NUMBER IS LESS THAN STARTING NUMBER!\n");
		}

		if (EndingNumber == StartingNumber)
		{
			printf("WRONG NUMBER , ENDING NUMBER IS EQUAL STARTING NUMBER!\n");
		}

	} while (EndingNumber <= StartingNumber);

	return EndingNumber;
}

GameSettings ReadRandomNumberLimits()
{
	GameSettings GameSettings;
	GameSettings.StartingNumber = ReadPositiveNumber("ENTER STARTING NUMBER");
	GameSettings.EndingNumber = ReadEndingNumber(GameSettings.StartingNumber);

	return GameSettings;
}

GameSettings ReadGameSettings()
{
	printf("ENTER THE LIMITS OF RANDOM NUMBER\n");
	GameSettings GameSettings = ReadRandomNumberLimits();
	GameSettings.RandomNumber = RandomNumber(GameSettings.StartingNumber, GameSettings.EndingNumber);
	GameSettings.GuessingCounter = 0;

	return GameSettings;
}

void NumberGuessingGame()
{
	GameSettings GameSettings;
	bool ExitFlag;
	do
	{
		SectionBanner("NUMBER GUESSING GAME", 2, "=");
		GameSettings = ReadGameSettings();
		ReadGuessedNumberAndCheckTheGuess(GameSettings.RandomNumber, GameSettings.GuessingCounter);

	} while (ExitFlag = DoYouWantToDoThisWithClear("\nDO YOU WANT TO PLAY AGAIN :-)"));

	if (!ExitFlag)
	{
		ExitProgram("GOOD BYE :-) , NUMBER GUESSING GAME");
	}
}

int main()
{
	srand((unsigned)time(NULL));

	NumberGuessingGame();

	return 0;
}