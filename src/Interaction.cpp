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

using namespace std;

void createLocation(string&name, pair<double,double>&coordinates )
{
	string temp;
	stringstream ss;
	double xCoord, yCoord;
	cout << "Enter the name of the location: ";

	getline(cin,name);

	cout << "Enter the x coordinate of the location: ";

	getline(cin,temp);
	ss << temp;
	ss >> xCoord;
	ss.clear();
	ss.str("");

	cout << "Enter the y coordinate of the location: ";

	getline(cin,temp);
	ss << temp;
	ss >> yCoord;
	ss.clear();
	ss.str("");

	coordinates.first = xCoord;
	coordinates.second = yCoord;
}

Garage * createGarage()
{
	string name;
	pair<double,double> coordinates;
	createLocation(name,coordinates);
	return new Garage(name,coordinates);
}

Container * createContainer()
{
	string name, temp;
	pair<double,double> coordinates;
	double quantity;
	garbageType type;
	createLocation(name,coordinates);
	getGarbageType();
	getQuantity();

	return new Container(name,coordinates,type,quantity);
}

double getQuantity()
{
	cout << "Enter the quantity of garbage it will be responsible for: ";
	return getDouble();
}

garbageType getGarbageType()
{
	garbageType type;
	int typeId;
	cout << "Enter the type of garbage it will be responsible for (glass - 1, plastic - 2, paper - 3, generic - 4): ";
	typeId = readUnsignedShortInt(1,4);
	switch(typeId)
	{
	case 1: type = garbageType::glass;
	break;
	case 2: type = garbageType::plastic;
	break;
	case 3: type = garbageType::paper;
	break;
	case 4: type = garbageType::generic;
	}
	return type;
}

Station * createStation()
{
	string name;
	pair<double,double> coordinates;
	createLocation(name,coordinates);
	return new Station(name,coordinates);
}

int getSourceLocationID()
{
	cout << "Enter the id of the source vertex: ";
	return getInt();
}

int getDestLocationID()
{
	cout << "Enter the id of the destination vertex: ";
	return getInt();
}

pair<int,int> createEdge()
{
	pair<int,int> vertexesIDs;
	vertexesIDs.first = getSourceLocationID();
	vertexesIDs.second = getDestLocationID();
	return vertexesIDs;
}

double createEdgeWeight()
{
	cout << "Enter the weight of the edge: ";
	return getDouble();
}

Vehicle * createVehicle()
{
	garbageType type;
	string plate;
	double quantity;
	cout << "Enter the plate number: ";
	getline(cin,plate);
	type = getGarbageType();
	quantity = getQuantity();
	return new Vehicle(plate, type, quantity);
}
