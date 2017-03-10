/*
 * Vehicle.h
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
#include "Auxiliary.h"

class Vehicle {
private:
	garbageType type;
	std::string matricula;
	bool full;
	double capacity;
public:
	Vehicle();
	virtual ~Vehicle();
};

#endif /* VEHICLE_H_ */
