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


bool Location::operator ==(const Location &location) const{
	return (this->name == location.name && this->coordinates == location.coordinates);
}

int Location::getId(){return this->id;}
string Location::getName(){return this->name;}
pair<double,double> Location::getCoordinates(){return this->coordinates;}
Location::~Location() {
	// TODO Auto-generated destructor stub
}

