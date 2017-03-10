/*
 * GarbageManagement.h
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#ifndef GARBAGEMANAGEMENT_H_
#define GARBAGEMANAGEMENT_H_

#include <vector>

#include "Vehicle.h"
#include "Container.h"
#include "graphviewer.h"

class GarbageManagement {
private:
	std::string name;
	GraphViewer * viewer;
	std::vector <Vehicle> vehicles;
	std::vector <Container> containers;
public:
	GarbageManagement();
	virtual ~GarbageManagement();
};

#endif /* GARBAGEMANAGEMENT_H_ */
