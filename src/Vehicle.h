/*
 * Vehicle.h
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
#include <vector>
#include "Auxiliary.h"

class Vehicle {
private:
	std::string plate;
	std::vector<garbageType> type;
	bool full;
	double currentCapacity;
	std::pair<double, double> currentCoordinates;
	double capacity;
public:
	Vehicle(std::string plate, garbageType type, double capacity);

	std::string getPlate();
	std::vector<garbageType> getType();
	bool isFull();
	double getCurrentCapacity();
	std::pair<double, double> getCurrentCoordinates();
	double getCapacity();

	void clearVehicle();
	void fillVehicle();
	bool loadCurrentCapacity(double load);
	void moveTo(double xCoord, double yCoord);
	void addType(garbageType type);
	void removeType(garbageType type);

	virtual ~Vehicle();
};

#endif /* VEHICLE_H_ */
