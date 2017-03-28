/*
 * Location.cpp
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */

#include "Location.h"

int Location::idCounter = 0;
using namespace std;

Location::Location(string name, pair<double,double> coordinates) {
	this->id = Location::idCounter;
	this->name = name;
	this->coordinates = coordinates;
	Location::idCounter++;
}

Location::Location(int id, pair<double,double> coordinates)
{
	this->id = id;
	this->coordinates = coordinates;
}

bool Location::operator ==(const Location &location) const{
	return (this->id == location.id);
}

int Location::getId(){return this->id;}
string Location::getName(){return this->name;}
pair<double,double> Location::getCoordinates(){return this->coordinates;}
Location::~Location() {
	// TODO Auto-generated destructor stub
}

