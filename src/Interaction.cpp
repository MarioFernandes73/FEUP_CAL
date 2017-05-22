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

string getContainerFirstStreet(){
	cout << "Containers can only be created in the corner of two streets." << endl;
	cout << "First street." << endl;
	return createEdgeName();
}

string getContainerSecondStreet(){
	cout << "Second street." << endl;
	return createEdgeName();
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

string createEdgeName(){
	string name = "";
	cout << "Enter the name of the street" << endl;
	getline(cin,name);
	return name;
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

int exactOrAproximated(){
	string temp;
	int res;
	cout << "Would you like to search for the streets using the exact(1) or aproximated(2) method?" << endl;
	do{
		getline(cin,temp);
		if(temp == "1"){
			res = 1;
			break;
		} else if(temp == "2") {
			res = 2;
			break;
		}
	}while(true);

return res;
}

int askDistance(){
	cout << "Would you like a certain distance?" << endl;
	if(!confirm()){
		return -1;
	}
	cout << "Please enter a reasonable distance: " << endl;
	return readUnsignedShortInt(0, 50);
}

Street * selectBestStreet(vector<Street *> streetVec){
	cout << "Please select the street you wish to register." << endl;
	for(unsigned int i = 0; i < streetVec.size(); i++){
		if(i > 7)
			break;
		cout << i << " - " << streetVec[i]->getName() << endl;
	}
	return streetVec[readUnsignedShortInt(0,7)];
}

void presentLocation(Location * loc){
	cout << "Your container has the id " << loc->getId() << endl;
}
