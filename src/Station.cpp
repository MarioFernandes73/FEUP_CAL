/*
 * Station.cpp
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */

#include "Station.h"
#include <string>

using namespace std;

Station::Station(string name, pair<double,double> coordinates):Location(name,coordinates) {
	this->setType(locationType::station);
}

Station::Station(long id, pair<double,double> coordinates):Location(id, coordinates)
{
	this->setName("station");
	this->setType(locationType::station);
}

Station::~Station() {
	// TODO Auto-generated destructor stub
}

