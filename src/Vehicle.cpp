/*
 * Vehicle.cpp
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(std::string plate, garbageType type, double capacity) {
	this->plate = plate;
	this->type.push_back(type);
	this->capacity = capacity;
	this->currentCapacity = 0;
	this->full = false;
	this->currentCoordinates = pair<double, double>(0, 0);
}

vector<garbageType> Vehicle::getType() {
	return this->type;
}

void Vehicle::fillVehicle() {
	this->full = true;
}

void Vehicle::clearVehicle() {
	this->full = false;
}

bool Vehicle::isFull() {
	return full;
}

bool Vehicle::loadCurrentCapacity(double load) {
	if (this->capacity >= this->currentCapacity + load) {
		this->currentCapacity += load;
		return true;
	}
	return false;
}

double Vehicle::getCapacity() {
	return this->capacity;
}

double Vehicle::getCurrentCapacity() {
	return this->currentCapacity;
}

void Vehicle::moveTo(double xCoord, double yCoord) {
	this->currentCoordinates.first = xCoord;
	this->currentCoordinates.second = yCoord;
}

pair<double, double> Vehicle::getCurrentCoordinates() {
	return this->currentCoordinates;
}

string Vehicle::getPlate() {
	return this->plate;
}

Vehicle::~Vehicle() {
	// TODO Auto-generated destructor stub
}

