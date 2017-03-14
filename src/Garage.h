/*
 * Garage.h
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */

#ifndef GARAGE_H_
#define GARAGE_H_

#include <vector>
#include "Location.h"
#include "Vehicle.h"

class Garage : public Location {
private:
	std::vector <Vehicle> vehicles;
public:
	Garage();
	virtual ~Garage();
};

#endif /* GARAGE_H_ */
