/*
 * Container.h
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Location.h"
#include "Auxiliary.h"
#include <string>

class Container: public Location {
private:
	garbageType type;
	double capacity;
public:
	Container(std::string name, std::pair<double, double> coordinates,
			garbageType type, double capacity);
	Container(long id, std::pair<double, double> coordinates, garbageType type,
			double quantity);
	garbageType getType();
	double getCapacity();
	virtual ~Container();
};

#endif /* CONTAINER_H_ */
