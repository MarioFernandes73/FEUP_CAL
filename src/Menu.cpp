/*
 * Menu.cpp
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */


#include "Menu.h"
#include "Auxiliary.h"
#include "MyExceptions.h"
#include "Interaction.h"
#include <iostream>

using namespace std;

short int initialMenu()
{
	short int option=-1;
	cout << TAB_BIG << "Initial Menu";
	cout << endl << endl;
	cout << TAB << "Choose your option";
	cout << endl << endl;
	cout << TAB << "1 - Create Garage" << endl;
	cout << TAB << "2 - Create Container" << endl;
	cout << TAB << "3 - Create Station" << endl;
	cout << TAB << "4 - Create Street" << endl;
	cout << TAB << "5 - Create Vehicle" << endl;
	cout << TAB << "6 - shortestpath" << endl;
	cout << TAB << "0 - Save & Exit" << endl;
	cout << endl;
	cout << "Please write your option here: ";


	while(true)
	{

		try{
			option = readUnsignedShortInt(0,5);
		option = readUnsignedShortInt(0,6);
		if(option <0)
			cout << "Error, please choose your option: ";
		else
			break;
		}
		catch(NoValidEntry& e){
			cout << "You have entered a non valid entry. Please insert a valid entry." << endl;
		}
	}

	return option;
}

void initialOptions(GarbageManagement & management)
{
	unsigned short int option;

	while((option=initialMenu()))
	switch (option)
	{
	case 1:management.addGarage(createGarage());
	break;
	case 2:management.addContainer(createContainer());
	break;
	case 3:management.addStation(createStation());
	break;
	case 4:management.addEdge(createEdgeWeight(),createEdge());
	break;
	case 5:management.addVehicle(getStationID(),createVehicle());
	break;
	case 6: //management.collectGarbage2();
		management.collectGarbage();
		//management.shortestPathSingleContainer(4);

	try{
		switch (option)
		{
		case 1:management.addGarage(createGarage());
		break;
		case 2:management.addContainer(createContainer());
		break;
		case 3:management.addStation(createStation());
		break;
		case 4:management.addEdge(createEdgeWeight(),createEdge());
		break;
		case 5:management.addVehicle(getStationID(),createVehicle());
		}
	}
	catch(NoValidEntry& e){
		cout << endl << "You have entered a non valid entry." << endl;
	}
}
