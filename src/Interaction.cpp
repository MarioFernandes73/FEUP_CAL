/*
 * Interaction.cpp
 *
 *  Created on: 26 Mar 2017
 *      Author: Mário
 */

#include <iostream>
#include <sstream>
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

Station * createStation()
{
	string name;
	pair<double,double> coordinates;
	createLocation(name,coordinates);
	return new Station(name,coordinates);
}
