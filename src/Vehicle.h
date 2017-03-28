/*
 * Vehicle.h
 *
 *  Created on: 7 Mar 2017
 *      Author: M�rio
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
#include "Auxiliary.h"

class Vehicle {
private:
	std::string plate;
	garbageType type;
	bool full;
	double capacity;
public:
	Vehicle(std::string plate, garbageType type, double capacity);
	virtual ~Vehicle();
};

#endif /* VEHICLE_H_ */
