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

}

void Garage::addVehicle(Vehicle * vehicle)
{
	this->vehicles.push_back(vehicle);
}

Garage::~Garage() {
	// TODO Auto-generated destructor stub
}

