#include <conio.h>
#include <fstream>
#include <assert.h>

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
	PersonListNode* root = new PersonListNode{"David", 12, nullptr};
	PersonListNode* node = new PersonListNode{"Mike", 11, nullptr}; 
	root->nextPerson = node; 


	



}