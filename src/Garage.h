/*
 * Garage.h
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */

#ifndef GARAGE_H_
#define GARAGE_H_

#include <vector>
#include <string>
#include "Location.h"
#include "Vehicle.h"

class Garage: public Location {
private:
	std::vector<Vehicle *> vehicles;
public:
	Garage() {
	}
	Garage(long id, std::pair<double, double> coordinates);
	Garage(std::string name, std::pair<double, double> coordinates);
	void addVehicle(Vehicle * vehicle);
	std::vector<Vehicle *> getVehicles();
	virtual ~Garage();
};

#endif /* GARAGE_H_ */
