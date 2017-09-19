/**
*	@file : main.cpp
*	@author :  Sri Gayatri
*	@date : 17/9/16
*	Purpose: Handles the program. 
*/
#include<iostream>
#include"hasht.h"
using namespace std;
void printMenu()
{
	std::cout << "\n\nPlease choose one of the following commands:\n"
			<< "1. insert\n"
			<< "2. delete\n"
			<< "3. print\n"
			<< "4. exit\n"
			<< "Enter your choice: ";
}

int main()
{
	int choice=0,value=0;	
	hasht h;
	do
	{
		printMenu();
		cin>>choice;
		if(choice==1)
		{
			cout<<"Which number do you want to insert into the hash table? ";
			cin>>value;
			h.insert(value);
		}
		else if(choice==2)
		{
			cout<<"Which number do you want to delete into the hash table? ";
			cin>>value;
			h.remove(value);		
		}
		else if(choice==3)
		{
			h.print();
		}
		else if(choice==4)
		{
			cout<<"Exiting...."<<endl;
			break;
		}

		else
			cout<<"Invalid choice"<<endl;
	}while(choice!=4);
	return 0;
}
