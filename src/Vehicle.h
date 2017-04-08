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
	std::pair<double,double> currentCoordinates;
	double capacity;
public:
	Vehicle(std::string plate, garbageType type, double capacity);
	std::vector<garbageType> getType();
	void clearVehicle();
	void fillVehicle();
	bool loadCurrentCapacity(double load);
	double getCurrentCapacity();
	bool isFull();
	void moveTo(double xCoord, double yCoord);
	std::pair<double,double> getCurrentCoordinates();
	double getCapacity();
	std::string getPlate();
	virtual ~Vehicle();
};

#endif /* VEHICLE_H_ */
