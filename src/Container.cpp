/*
 * Container.cpp
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#include "Container.h"

using namespace std;

Container::Container(string name, pair<double, double> coordinates,
		garbageType type, double quantity) :
		Location(name, coordinates) {
	this->type = type;
	this->capacity = quantity;
	this->setType(locationType::container);
}

Container::Container(long id, pair<double, double> coordinates,
		garbageType type, double quantity) :
		Location(id, coordinates) {
	this->setName("container");
	this->type = type;
	this->capacity = quantity;
	this->setType(locationType::container);
}

garbageType Container::getType() {
	return this->type;
}

double Container::getCapacity() {
	return this->capacity;
}

Container::~Container() {
	// TODO Auto-generated destructor stub
}

