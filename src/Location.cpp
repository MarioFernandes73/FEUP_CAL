/*
 * Location.cpp
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */

#include "Location.h"

int Location::idCounter = 0;
using namespace std;

Location::Location():type(locationType::location){

}

Location::Location(string name, pair<double,double> coordinates):type(locationType::location) {
	this->id = Location::idCounter;
	this->name = name;
	this->coordinates = coordinates;
	this->full = false;
	Location::idCounter++;
}


Location::Location(int id, pair<double,double> coordinates)
{
	this->id = id;
	this->coordinates = coordinates;
	this->full = false;
}

bool Location::operator ==(const Location &location) const{
	return (this->getId() == location.getId());
}

bool Location::operator !=(const Location &location) const{
	return (this->getId() != location.getId());
}

int Location::getId()const {return this->id;}
string Location::getName(){return this->name;}
pair<double,double> Location::getCoordinates(){return this->coordinates;}

locationType Location::getLocationType()
{
	return this->type;
}

void Location::fillContainer()
{
	this->full = true;
}

void Location::clearContainer()
{
	this->full = false;
}

bool Location::isFull()
{
	return full;
}

void Location::setType(locationType type)
{
	this->type = type;
}

void Location::setID(int id)
{
	this->id = id;
}

Location::~Location() {
	// TODO Auto-generated destructor stub
}

