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
void Console::Read(char* name = nullptr,int arrLength = 0, int* age = nullptr)
{
	assert((name != nullptr || age != nullptr) && "didn`t pass the argument");

	//if try to get a name
	if (name != nullptr)
	{
		int inputLength = 0;
		char tempChar = ' ';
		while (inputLength < arrLength - 1 && tempChar != '\r')
		{
			tempChar = _getch();
			if (tempChar != '\r')
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
		int  maxIntLen = 2;
		int charToInt = 0;
		char tempChar = ' ';

		//GET NUMBER IN RANGE FROM 0 TO 99
		while (maxIntLen != 0 && tempChar != '\r')
		{
			tempChar = _getch();
			if (tempChar != '\r' && tempChar < 58 && tempChar > 47)
			{
				charToInt = (charToInt * 10) + (tempChar - '0');
				_putch(tempChar);
				--maxIntLen;
			}
		}
		*age = charToInt;

	}

	_putch('\r');
	_putch('\n');

}
