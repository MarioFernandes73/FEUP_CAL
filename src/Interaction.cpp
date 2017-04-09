/*
 * Interaction.cpp
 *
 *  Created on: 26 Mar 2017
 *      Author: Mário
 */

#include <iostream>
#include <sstream>
#include <string>
#include "Interaction.h"
#include "MyExceptions.h"

using namespace std;

bool isValidCoordinate(string temp) {
	bool flag = 0;

	for (unsigned int i = 0; i < temp.size(); i++) {
		if (flag == 0 && temp[i] == '.') {
			flag++;
			continue;
		}
		if (!isdigit(temp[i]) || (flag > 0 && temp[i] == '.'))
			return false;
	}
	return true;
}

void createLocation(string&name, pair<double, double>&coordinates) {
	string temp;
	stringstream ss;
	double xCoord, yCoord;
	cout << "Enter the name of the location: ";

	getline(cin, name);

	if (name == "" || isdigit(name[0])) {
		throw NoValidEntryException();
	}

	cout << "Enter the x coordinate of the location: ";

	getline(cin, temp);

	if (!isValidCoordinate(temp)) {
		throw NoValidEntryException();
	}

	ss << temp;
	ss >> xCoord;
	ss.clear();
	ss.str("");

	cout << "Enter the y coordinate of the location: ";

	getline(cin, temp);

	if (!isValidCoordinate(temp)) {
		throw NoValidEntryException();
	}

	ss << temp;
	ss >> yCoord;
	ss.clear();
	ss.str("");

	coordinates.first = xCoord;
	coordinates.second = yCoord;
}

Location * createNewLocation() {
	string name;
	pair<double, double> coordinates;

	createLocation(name, coordinates);
	return new Location(name, coordinates);
}

Garage * createGarage() {
	string name;
	pair<double, double> coordinates;

	createLocation(name, coordinates);
	return new Garage(name, coordinates);
}

Container * createContainer() {
	string name, temp;
	pair<double, double> coordinates;
	double quantity;
	garbageType type;

	createLocation(name, coordinates);
	type = getGarbageType();
	quantity = getQuantity();
	return new Container(name, coordinates, type, quantity);
}

double getQuantity() {
	cout << "Enter the quantity of garbage it will be responsible for: ";
	return getDouble();
}

garbageType getGarbageType() {
	garbageType type;
	int typeId;
	cout
			<< "Enter the type of garbage it will be responsible for (glass - 1, plastic - 2, paper - 3, generic - 4): ";
	typeId = readUnsignedShortInt(1, 4);
	switch (typeId) {
	case 1:
		type = garbageType::glass;
		break;
	case 2:
		type = garbageType::plastic;
		break;
	case 3:
		type = garbageType::paper;
		break;
	case 4:
		type = garbageType::generic;
	}
	return type;
}

Station * createStation() {
	string name;
	pair<double, double> coordinates;

	createLocation(name, coordinates);
	return new Station(name, coordinates);
}

long getSourceLocationID() {
	cout << "Enter the id of the source vertex: ";
	return getInt();
}

long getDestLocationID() {
	cout << "Enter the id of the destination vertex: ";
	return getInt();
}

pair<long, long> createEdge() {
	pair<long, long> vertexesIDs;
	vertexesIDs.first = getSourceLocationID();
	vertexesIDs.second = getDestLocationID();
	return vertexesIDs;
}

double createEdgeWeight() {
	cout << "Enter the weight of the edge: ";
	return getDouble();
}

Vehicle * createVehicle() {
	garbageType type;
	string plate;
	double quantity;
	cout << "Enter the plate number: ";
	getline(cin, plate);
	type = getGarbageType();
	quantity = getQuantity();
	return new Vehicle(plate, type, quantity);
}

long getLocationID() {
	cout << "Enter the id of a location: ";
	return getLong();
}

long getStationID() {
	cout << "Enter the id of a station: ";
	return getLong();
}

string getPlate() {
	string temp;
	cout << "Enter the plate of the vehicle: ";
	getline(cin, temp);
	return temp;
}

int getAlgorithm() {
	cout
			<< "Enter the algorithm you wish to use (1 - FloydWarshall, 2 - Dijkstra): ";
	return readUnsignedShortInt(1, 2);
}
