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
		const char* menu = "(l)oad (s)ave (a)dd (q)uit or (p)rint?\n";
		Console::Print(menu);
		char menuChoice = _getch();

		switch (menuChoice)
		{
			case  'l': // load data from a file
			{
				//if there is data in the list this function doesn`t  delete it

				char fileName[g_FILE_NAME_SIZE];
				Console::Print("Enter file name: ");
				Console::Read(fileName, g_FILE_NAME_SIZE, nullptr);

				std::ifstream file(fileName, std::ios_base::binary); 
				if (file.is_open())
				{
					//get size of the file
					file.seekg(0, file.end); 
					int fileSize = file.tellg(); 
					file.seekg(0, file.beg); 

					//read data from file to PersonData object
					int writtenBytes = 0; 
					while (writtenBytes != fileSize)
					{
						PersonData person; 

						file.read(reinterpret_cast<char*>(&(person.name)), g_NAME_SIZE);
						writtenBytes += g_NAME_SIZE; 

						file.read(reinterpret_cast<char*>(&(person.age)), sizeof(int));
						writtenBytes += sizeof(int); 

						root.push_back(person); 
					} 

					file.close(); 

					Console::Print("*******LOADED********\n\n"); 
				}
				else
				{
					Console::Print("File with this name doesn`t exist.\n"); 
				}

			}break;
			case 's': //save data to a file 
			{
				char fileName[g_FILE_NAME_SIZE]; 
				Console::Print("Enter file name: "); 
				Console::Read(fileName, g_FILE_NAME_SIZE, nullptr); 
			
				//try to open file
				//if file isn`t empty this function adds data to already existed 
				std::ofstream file(fileName, std::ios_base::binary|std::ios_base::ate);
				if (file.is_open())
				{
					for (auto iter = root.begin(); iter != root.end(); ++iter)
					{
						file.write(reinterpret_cast<char*>(&(iter->name)), g_NAME_SIZE);
						file.write(reinterpret_cast<char*>(&(iter->age)), sizeof(int));
					} 
					
					file.close();

					Console::Print("*******SAVED********\n\n");
				} 
				else
				{
					Console::Print("Can`t open file with this name\n");
				}
				
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
					Console::Print("*******DATA*******\n\n"); 
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