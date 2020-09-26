#include "Console.h"
#include <conio.h>
#include <assert.h>

//PRINT TO CONSOLE
void Console::Print(const char * str)
{
	int index = 0;
	while (str[index] != '\0')
	{
		_putch(str[index]);
		++index;
	}
}

//GET INPUT FROM CONSOLE
void Console::Read(char* name,int arrLength, int* age)
{
	// pass 'name' and 'arrLength' parameters if you plan to read a name otherwise pass 'age' parametr to get only digits from input
	assert((name != nullptr || age != nullptr) && "didn`t pass the argument"); 
	
	//if try to get a name
	if (name != nullptr)
	{
		int inputLength = 0;
		char tempChar = ' ';
		while (inputLength < arrLength - 1 && tempChar != '\r')
		{
			tempChar = _getch(); 
            

			if (tempChar == '\b')
			{
				//process deleting symbols from array and console
				if (inputLength > 0)
				{
					_putch(tempChar);
					_putch(' ');
					_putch(tempChar);

					--inputLength;
				} 
			}
			else if (tempChar != '\r')
			{
				_putch(tempChar);
				name[inputLength++] = tempChar;
			}
		}
		name[inputLength] = '\0';

	}
	//if try to get an age
	else if (age != nullptr)
	{
		constexpr int maxIntLen = 2;
		char numbersArr[maxIntLen]{};

		//GET NUMBER IN RANGE FROM 0 TO 99
		char tempChar = ' '; 
		int countNumbers = 0;
		while (tempChar != '\r')
		{
			tempChar = _getch();

			if (tempChar == '\b')
			{
				//process deleting symbols from array and console
				if (countNumbers > 0)
				{
					_putch(tempChar);
					_putch(' ');
					_putch(tempChar);

					--countNumbers;
				}
			}
			//get only digits without any other symbols
			else if (tempChar != '\r' && tempChar < 58 && tempChar > 47 && countNumbers < maxIntLen)
			{
				numbersArr[countNumbers] = tempChar;
				_putch(tempChar);
				++countNumbers;
			}

		}

		//in case if user entered less numbers then maxIntLen
		if (countNumbers < maxIntLen)
		{
			numbersArr[countNumbers] = '-'; 
		}


		//translate chars to integer
		int charToInt = 0; 
		for (int i = 0; i < maxIntLen && numbersArr[i] != '-'; ++i)
		{  
			charToInt = charToInt * 10 + numbersArr[i] - '0'; 
		}
		*age = charToInt;
	}

	_putch('\r');
	_putch('\n');

}
