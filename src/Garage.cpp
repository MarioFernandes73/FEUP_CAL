/*
 * Garage.cpp
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */

#include <string>
#include "Garage.h"

using namespace std;

Garage::Garage(string name, pair<double,double> coordinates):Location(name, coordinates) {
	this->setType(locationType::garage);
}

void Garage::addVehicle(Vehicle * vehicle)
{
	this->vehicles.push_back(vehicle);
}

vector<Vehicle *> Garage::getVehicles()
{
	return this->vehicles;
}

Garage::~Garage() {
	// TODO Auto-generated destructor stub
}

