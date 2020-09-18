#include <fstream>
#include <assert.h>
#include <conio.h>

#include "Console.h"


//LENGTH FOR A PERSON NAME
const int g_NAME_SIZE = 30; 

//STORES SINGLE PERSON DATA
struct PersonData
{
	char name[g_NAME_SIZE];
	int  age;
};

// LIST OF SINGLE PERSON DATA
struct PersonListNode
{
	PersonData data;
	PersonListNode* nextPerson = nullptr;

	~PersonListNode()
	{
		delete nextPerson; 
	}
};


#include <iostream>
int main()
{
	//persons data 
	PersonListNode* root = nullptr;

	bool exit = false; 
	while (!exit)
	{	
		const char* menu = "((l)oad (s)ave (a)dd (q)uit or (p)rint?\n";
		Console::Print(menu);
		char menuChoice = _getch();

		switch (menuChoice)
		{
			case  'l': // load data from a file
			{

			}break;
			case 's': //save data to a file 
			{

			}break;
			case 'a': // add data to list
			{

			}break;
			case 'p': //print data from list
			{

			}break;
			case 'q': //quit the app
			{
				exit = true; 
			}break;
			default: // wrong input
			{
				Console::Print("Dont have this option\n");
			}break;
		}
	} 

}