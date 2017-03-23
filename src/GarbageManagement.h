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
#include "graphviewer.h"
#include "Graph.h"

class GarbageManagement {
private:
	//Graph graph;
	std::string name;
	GraphViewer * viewer;
	std::vector <Vehicle *> vehicles;
	//3 vectors
	std::vector <Garage *> garages;
	std::vector <Container *> containers;
	std::vector <Station *> stations;

public:
	GarbageManagement();
	virtual ~GarbageManagement();
};

#endif /* GARBAGEMANAGEMENT_H_ */
