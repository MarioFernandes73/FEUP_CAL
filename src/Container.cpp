/*
 * Container.cpp
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#include "Container.h"

using namespace std;

Container::Container(string name, pair<double,double> coordinates, garbageType type, double quantity):Location(name, coordinates) {
this->type = type;
this->quantity = quantity;

}

Container::~Container() {
	// TODO Auto-generated destructor stub
}

