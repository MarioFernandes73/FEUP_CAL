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
#include <ctime>

using namespace std;

short int initialMenu() {
	cout << TAB_BIG << "Initial Menu";
	cout << endl << endl;
	cout << TAB << "Choose your option";
	cout << endl << endl;
	cout << TAB << "1 - Vertex Menu" << endl;
	cout << TAB << "2 - Edge Menu" << endl;
	cout << TAB << "3 - Vehicle Menu" << endl;
	cout << TAB << "4 - Settings Menu" << endl;
	cout << TAB << "5 - Collect garbage" << endl;
	cout << TAB << "6 - Evaluate Connectivity" << endl;
	cout << TAB << "7 - Stress test" << endl;
	cout << TAB << "0 - Save & Exit" << endl;
	cout << endl;
	cout << "Please write your option here: ";

	return readUnsignedShortInt(0, 7);
}

short int vertexMenu() {
	cout << TAB_BIG << "Vertex Menu";
	cout << endl << endl;
	cout << TAB << "Choose your option";
	cout << endl << endl;
	cout << TAB << "1 - Create Location" << endl;
	cout << TAB << "2 - Create Garage" << endl;
	cout << TAB << "3 - Create Container" << endl;
	cout << TAB << "4 - Create Station" << endl;
	cout << TAB << "5 - Remove Location" << endl;
	cout << TAB << "6 - Remove Garage" << endl;
	cout << TAB << "7 - Remove Container" << endl;
	cout << TAB << "8 - Remove Station" << endl;
	cout << TAB << "0 - Back" << endl;
	cout << endl;
	cout << "Please write your option here: ";

	return readUnsignedShortInt(0, 8);
}

short int edgeMenu() {
	cout << TAB_BIG << "Edge Menu";
	cout << endl << endl;
	cout << TAB << "Choose your option";
	cout << endl << endl;
	cout << TAB << "1 - Create Edge" << endl;
	cout << TAB << "2 - Remove Edge" << endl;
	cout << TAB << "0 - Back" << endl;
	cout << endl;
	cout << "Please write your option here: ";

	return readUnsignedShortInt(0, 2);
}

short int vehicleMenu() {
	cout << TAB_BIG << "Vehicle Menu";
	cout << endl << endl;
	cout << TAB << "Choose your option";
	cout << endl << endl;
	cout << TAB << "1 - Create Vehicle" << endl;
	cout << TAB << "2 - Add vehicle type" << endl;
	cout << TAB << "3 - Remove vehicle type" << endl;
	cout << TAB << "4 - Remove vehicle" << endl;
	cout << TAB << "0 - Back" << endl;
	cout << endl;
	cout << "Please write your option here: ";

	return readUnsignedShortInt(0, 4);
}

short int settingsMenu() {
	cout << TAB_BIG << "Settings Menu";
	cout << endl << endl;
	cout << TAB << "Choose your option";
	cout << endl << endl;
	cout << TAB << "1 - Set Garage" << endl;
	cout << TAB << "2 - Set Container" << endl;
	cout << TAB << "3 - Set Station" << endl;
	cout << TAB << "4 - Fill Container" << endl;
	cout << TAB << "5 - Clear Container" << endl;
	cout << TAB << "0 - Back" << endl;
	cout << endl;
	cout << "Please write your option here: ";

	return readUnsignedShortInt(0, 7);
}

void initialOptions(GarbageManagement & management) {
	unsigned int short option = 1;
	while (option > 0)
		try {
			switch (option = initialMenu()) {
			case 1:
				vertexOptions(management);
				break;
			case 2:
				edgeOptions(management);
				break;
			case 3:
				vehicleOptions(management);
				break;
			case 4:
				settingsOptions(management);
				break;
			case 5:
				management.simulatePath(
						management.collectGarbage(getAlgorithm()));
				break;
			case 6:
				management.evaluateConnectivity();
				break;
			case 7:
				clock_t begin = clock();
				for(unsigned int i = 0; i < 100 ; i++)
				{
					management.collectGarbage(1);
				}
				clock_t middle = clock();
				for(unsigned int i = 0; i < 100 ; i++)
				{
					management.collectGarbage(2);
				}
				clock_t end = clock();
				cout << "Floyd Warshall's:" << double(middle - begin) / CLOCKS_PER_SEC << endl;
				cout << "Dijkstra's:" << double(end - middle) / CLOCKS_PER_SEC << endl;

			}
		} catch (OutOfBondsException& e) {
			cout << endl << "Value is out of bonds!" << endl;
		}
		catch (ImpossibleException& e) {
			cout << endl << "Impossible graph to collect garbage from." << endl;
		}
}

void vertexOptions(GarbageManagement & management) {
	unsigned int short option = 1;
	while (option > 0)
		try {
			switch (option = vertexMenu()) {
			case 1:
				management.addLocation(createNewLocation());
				break;
			case 2:
				management.addGarage(createGarage());
				break;
			case 3:
				management.addContainer(createContainer());
				break;
			case 4:
				management.addStation(createStation());
				break;
			case 5:
				management.removeLocation(getLocationID());
				break;
			case 6:
				management.removeGarage(getLocationID());
				break;
			case 7:
				management.removeContainer(getLocationID());
				break;
			case 8:
				management.removeStation(getLocationID());
			}
		} catch (OutOfBondsException& e) {
			cout << endl << "Value is out of bonds!" << endl;
		} catch (NoValidEntryException& e) {
			cout << endl << "You have entered a non valid entry." << endl;
		}
}

void edgeOptions(GarbageManagement & management) {
	unsigned int short option = 1;
	while (option > 0)
		try {
			switch (option = edgeMenu()) {
			case 1:
				management.addEdge(createEdgeWeight(), createEdge());
				break;
			case 2:
				management.removeEdge(createEdge());
			}
		} catch (OutOfBondsException& e) {
			cout << endl << "Value is out of bonds!" << endl;
		} catch (NoValidEntryException& e) {
			cout << endl << "You have entered a non valid entry." << endl;
		}
}

void vehicleOptions(GarbageManagement & management) {
	unsigned int short option = 1;
	while (option > 0)
		try {
			switch (option = vehicleMenu()) {
			case 1:
				management.addVehicle(getStationID(), createVehicle());
				break;
			case 2:
				management.addVehicleType(getGarbageType(), getPlate());
				break;
			case 3:
				management.removeVehicleType(getGarbageType(), getPlate());
				break;
			case 4:
				management.removeVehicle(getPlate());
			}
		} catch (OutOfBondsException& e) {
			cout << endl << "Value is out of bonds!" << endl;
		} catch (NoValidEntryException& e) {
			cout << endl << "You have entered a non valid entry." << endl;
		} catch (VehicleNotFoundException& e) {
			cout << endl << "Vehicle with that plate does not exist." << endl;
		}
}

void settingsOptions(GarbageManagement & management) {
	unsigned int short option = 1;
	while (option > 0)
		try {
			switch (option = settingsMenu()) {
			case 1:
				management.setGarage(getLocationID());
				break;
			case 2:
				management.setContainer(getLocationID(), getGarbageType(),
						getQuantity());
				break;
			case 3:
				management.setStation(getLocationID());
				break;
			case 4:
				management.fillContainer(getLocationID());
				break;
			case 5:
				management.clearContainer(getLocationID());
				break;
			}
		} catch (OutOfBondsException& e) {
			cout << endl << "Value is out of bonds!" << endl;
		} catch (NoValidEntryException& e) {
			cout << endl << "You have entered a non valid entry." << endl;
		}
}
