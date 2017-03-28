/*
 * Vehicle.cpp
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#include "Vehicle.h"

Vehicle::Vehicle(std::string plate, garbageType type, double capacity) {
this->plate = plate;
this->type = type;
this->capacity = capacity;
this->full = false;
}

void Vehicle::fillVehicle()
{
	this->full = true;
}

void Vehicle::clearVehicle()
{
	this->full = false;
}

Vehicle::~Vehicle() {
	// TODO Auto-generated destructor stub
}

