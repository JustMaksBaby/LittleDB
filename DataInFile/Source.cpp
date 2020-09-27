#include <fstream>
#include <assert.h>
#include <conio.h>
#include <list>
#include "Console.h"


//LENGTH FOR A PERSON NAME
const int g_NAME_SIZE = 30; 
const int g_FILE_NAME_SIZE = 20; 

//STORES SINGLE PERSON DATA
struct PersonData
{
	char name[g_NAME_SIZE];
	int  age;
};

int main()
{
	//persons data 
	std::list<PersonData> root; 

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
				PersonData person;
				//get name
				Console::Print("Enter a name: "); 
				Console::Read(person.name, g_NAME_SIZE, nullptr);  
				
				//get age
				Console::Print("Enter age(0-99): "); 
				Console::Read(nullptr, NULL, &(person.age)); 


				root.push_back(person); 
			}break;
			case 'p': //print data from list
			{
				if (root.empty())
				{
					Console::Print("No data to show.\n"); 
				}
				else
				{
					Console::Print("*******DATA*******"); 
					for (auto iter = root.begin(); iter != root.end(); ++iter)
					{
						Console::Print(iter->name); 
						Console::Print("| "); 
						for (int i = 0; i < iter->age; ++i)
						{
							_putch('='); 
						}
						_putch('\n'); 
					}
				}

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