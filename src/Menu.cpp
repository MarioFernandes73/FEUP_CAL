/*
 * Menu.cpp
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */


#include "Menu.h"
#include "Auxiliary.h"
//#include "MyExceptions.h"
#include "Interface.h"
#include <iostream>
using namespace std;

short int initialMenu()
{
	short int option=-1;
	cout << TAB_BIG << "Initial Menu";
	cout << endl << endl;
	cout << TAB << "Choose your option";
	cout << endl << endl;
	cout << TAB << "1 - Menu of Students" << endl;
	cout << TAB << "0 - Save & Exit" << endl;
	cout << endl;
	cout << "Please write your option here: ";


	while(true)
	{
		option = readUnsignedShortInt(0,1);
		if(option <0)
			cout << "Error, please choose your option: ";
		else
			break;
	}



	return option;
}

void initialOptions(GarbageManagement & management)
{
	unsigned short int option;

	while((option=initialMenu()))
	switch (option)
	{

	break;
	}
}

